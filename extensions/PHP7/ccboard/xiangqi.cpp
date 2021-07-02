﻿
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <string>

#include "xiangqi.h"


using namespace std;

	//初始化
	void init()
	{
		attack_init();
	}
	template<typename T>
	inline const T& Max(const T& a, const T& b)
	{
		return a > b ? a : b;
	};
	template<typename T>
	inline const T& Min(const T& a, const T& b)
	{
		return a < b ? a : b;
	};
	template<typename T>
	inline const T Abs(const T& a)
	{
		return a >= 0 ? a : -a;
	};
	template<typename T>
	inline bool Mid(const T& m, const T& a, const T& b)
	{
		return ((m > a && m < b) || (m > b && m < a));
	};

	const U8 Sq_Rank[90] = 
	{
		Rank_0,Rank_0,Rank_0,Rank_0,Rank_0,Rank_0,Rank_0,Rank_0,Rank_0,
		Rank_1,Rank_1,Rank_1,Rank_1,Rank_1,Rank_1,Rank_1,Rank_1,Rank_1,
		Rank_2,Rank_2,Rank_2,Rank_2,Rank_2,Rank_2,Rank_2,Rank_2,Rank_2,
		Rank_3,Rank_3,Rank_3,Rank_3,Rank_3,Rank_3,Rank_3,Rank_3,Rank_3,
		Rank_4,Rank_4,Rank_4,Rank_4,Rank_4,Rank_4,Rank_4,Rank_4,Rank_4,
		Rank_5,Rank_5,Rank_5,Rank_5,Rank_5,Rank_5,Rank_5,Rank_5,Rank_5,
		Rank_6,Rank_6,Rank_6,Rank_6,Rank_6,Rank_6,Rank_6,Rank_6,Rank_6,
		Rank_7,Rank_7,Rank_7,Rank_7,Rank_7,Rank_7,Rank_7,Rank_7,Rank_7,
		Rank_8,Rank_8,Rank_8,Rank_8,Rank_8,Rank_8,Rank_8,Rank_8,Rank_8,
		Rank_9,Rank_9,Rank_9,Rank_9,Rank_9,Rank_9,Rank_9,Rank_9,Rank_9,
	};
	const U8 Sq_File[90] =
	{
		File_A, File_B, File_C, File_D, File_E, File_F, File_G, File_H, File_I,
		File_A, File_B, File_C, File_D, File_E, File_F, File_G, File_H, File_I,
		File_A, File_B, File_C, File_D, File_E, File_F, File_G, File_H, File_I,
		File_A, File_B, File_C, File_D, File_E, File_F, File_G, File_H, File_I,
		File_A, File_B, File_C, File_D, File_E, File_F, File_G, File_H, File_I,
		File_A, File_B, File_C, File_D, File_E, File_F, File_G, File_H, File_I,
		File_A, File_B, File_C, File_D, File_E, File_F, File_G, File_H, File_I,
		File_A, File_B, File_C, File_D, File_E, File_F, File_G, File_H, File_I,
		File_A, File_B, File_C, File_D, File_E, File_F, File_G, File_H, File_I,
		File_A, File_B, File_C, File_D, File_E, File_F, File_G, File_H, File_I,
	};
	const U8 Sq_Color[90] = 
	{
		White,White,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,
	};
	const U8 Sq_File_Mirror[90] = {
		SQ_I0,SQ_H0,SQ_G0,SQ_F0,SQ_E0,SQ_D0,SQ_C0,SQ_B0,SQ_A0,
		SQ_I1,SQ_H1,SQ_G1,SQ_F1,SQ_E1,SQ_D1,SQ_C1,SQ_B1,SQ_A1,
		SQ_I2,SQ_H2,SQ_G2,SQ_F2,SQ_E2,SQ_D2,SQ_C2,SQ_B2,SQ_A2,
		SQ_I3,SQ_H3,SQ_G3,SQ_F3,SQ_E3,SQ_D3,SQ_C3,SQ_B3,SQ_A3,
		SQ_I4,SQ_H4,SQ_G4,SQ_F4,SQ_E4,SQ_D4,SQ_C4,SQ_B4,SQ_A4,
		SQ_I5,SQ_H5,SQ_G5,SQ_F5,SQ_E5,SQ_D5,SQ_C5,SQ_B5,SQ_A5,
		SQ_I6,SQ_H6,SQ_G6,SQ_F6,SQ_E6,SQ_D6,SQ_C6,SQ_B6,SQ_A6,
		SQ_I7,SQ_H7,SQ_G7,SQ_F7,SQ_E7,SQ_D7,SQ_C7,SQ_B7,SQ_A7,
		SQ_I8,SQ_H8,SQ_G8,SQ_F8,SQ_E8,SQ_D8,SQ_C8,SQ_B8,SQ_A8,
		SQ_I9,SQ_H9,SQ_G9,SQ_F9,SQ_E9,SQ_D9,SQ_C9,SQ_B9,SQ_A9,
	};
	const U8 Sq_Rank_Mirror[90] = {
		SQ_A9, SQ_B9, SQ_C9, SQ_D9, SQ_E9, SQ_F9, SQ_G9, SQ_H9, SQ_I9,
		SQ_A8, SQ_B8, SQ_C8, SQ_D8, SQ_E8, SQ_F8, SQ_G8, SQ_H8, SQ_I8,
		SQ_A7, SQ_B7, SQ_C7, SQ_D7, SQ_E7, SQ_F7, SQ_G7, SQ_H7, SQ_I7,
		SQ_A6, SQ_B6, SQ_C6, SQ_D6, SQ_E6, SQ_F6, SQ_G6, SQ_H6, SQ_I6,
		SQ_A5, SQ_B5, SQ_C5, SQ_D5, SQ_E5, SQ_F5, SQ_G5, SQ_H5, SQ_I5,
		SQ_A4, SQ_B4, SQ_C4, SQ_D4, SQ_E4, SQ_F4, SQ_G4, SQ_H4, SQ_I4,
		SQ_A3, SQ_B3, SQ_C3, SQ_D3, SQ_E3, SQ_F3, SQ_G3, SQ_H3, SQ_I3,
		SQ_A2, SQ_B2, SQ_C2, SQ_D2, SQ_E2, SQ_F2, SQ_G2, SQ_H2, SQ_I2,
		SQ_A1, SQ_B1, SQ_C1, SQ_D1, SQ_E1, SQ_F1, SQ_G1, SQ_H1, SQ_I1,
		SQ_A0, SQ_B0, SQ_C0, SQ_D0, SQ_E0, SQ_F0, SQ_G0, SQ_H0, SQ_I0,
	};
	const S8 White_King_Pos[90] =
	{
		-1, -1, -1,  0,  1,  2, -1, -1, -1,
		-1, -1, -1,  3,  4,  5, -1, -1, -1,
		-1, -1, -1,  6,  7,  8, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1,
	};
	const S8 White_Advisor_Pos[90] =
	{
		-1, -1, -1,  0, -1,  1, -1, -1, -1,
		-1, -1, -1, -1,  2, -1, -1, -1, -1,
		-1, -1, -1,  3, -1,  4, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1,
	};
	const S8 White_Bishop_Pos[90] =
	{
		-1, -1,  0, -1, -1, -1,  1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1,
		 2, -1, -1, -1,  3, -1, -1, -1,  4,
		-1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1,  5, -1, -1, -1,  6, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1,
	};
	const S8 White_Pawn_Pos[90] =
	{
		-1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1,
		 0, -1,  1, -1,  2, -1,  3, -1,  4,
		 5, -1,  6, -1,  7, -1,  8, -1,  9,
		10, 11, 12, 13, 14, 15, 16, 17, 18,
		19, 20, 21, 22, 23, 24, 25, 26, 27,
		28, 29, 30, 31, 32, 33, 34, 35, 36,
		37, 38, 39, 40, 41, 42, 43, 44, 45,
		46, 47, 48, 49, 50, 51, 52, 53, 54,
	};
	const S8 King_Pos_Index[90] = 
	{
		-1, -1, -1,  0,  1,  2, -1, -1, -1, 
		-1, -1, -1,  3,  4,  5, -1, -1, -1, 
		-1, -1, -1,  6,  7,  8, -1, -1, -1, 
		-1, -1, -1, -1, -1, -1, -1, -1, -1, 
		-1, -1, -1, -1, -1, -1, -1, -1, -1, 
		-1, -1, -1, -1, -1, -1, -1, -1, -1, 
		-1, -1, -1, -1, -1, -1, -1, -1, -1, 
		-1, -1, -1,  9, 10, 11, -1, -1, -1, 
		-1, -1, -1, 12, 13, 14, -1, -1, -1, 
		-1, -1, -1, 15, 16, 17, -1, -1, -1, 
	};
	const S8 Advisor_Pos_Index[90] = 
	{
		-1, -1, -1,  0, -1,  1, -1, -1, -1, 
		-1, -1, -1, -1,  2, -1, -1, -1, -1, 
		-1, -1, -1,  3, -1,  4, -1, -1, -1, 
		-1, -1, -1, -1, -1, -1, -1, -1, -1, 
		-1, -1, -1, -1, -1, -1, -1, -1, -1, 
		-1, -1, -1, -1, -1, -1, -1, -1, -1, 
		-1, -1, -1, -1, -1, -1, -1, -1, -1, 
		-1, -1, -1,  5, -1,  6, -1, -1, -1, 
		-1, -1, -1, -1,  7, -1, -1, -1, -1, 
		-1, -1, -1,  8, -1,  9, -1, -1, -1, 
	};
	const S8 Bishop_Pos_Index[90] = 
	{
		-1, -1,  0, -1, -1, -1,  1, -1, -1, 
		-1, -1, -1, -1, -1, -1, -1, -1, -1, 
		 2, -1, -1, -1,  3, -1, -1, -1,  4, 
		-1, -1, -1, -1, -1, -1, -1, -1, -1, 
		-1, -1,  5, -1, -1, -1,  6, -1, -1, 
		-1, -1,  7, -1, -1, -1,  8, -1, -1, 
		-1, -1, -1, -1, -1, -1, -1, -1, -1, 
		 9, -1, -1, -1, 10, -1, -1, -1, 11, 
		-1, -1, -1, -1, -1, -1, -1, -1, -1, 
		-1, -1, 12, -1, -1, -1, 13, -1, -1, 
	};

	const char PieceString[20] = "?KRNCABP?krncabp";
	const char PieceFromChar[128] = {
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		0,  5,  6,  4,  0,  6,  0,  5,  3,  0,  0,  1,  0,  0,  3,  0,
		7,  0,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		0, 13, 14, 12,  0, 14,  0, 13, 11,  0,  0,  9,  0,  0, 11,  0,
		15, 0, 10,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	};
	const BITBOARD SQ_BB_MASK[92] = 
	{
		BITBOARD(0x0000000000080000, 0x0000000000000000), BITBOARD(0x0000000000100000, 0x0000000000000000),
		BITBOARD(0x0000000000200000, 0x0000000000000000), BITBOARD(0x0000000000400000, 0x0000000000000000),
		BITBOARD(0x0000000000800000, 0x0000000000000000), BITBOARD(0x0000000001000000, 0x0000000000000000),
		BITBOARD(0x0000000002000000, 0x0000000000000000), BITBOARD(0x0000000004000000, 0x0000000000000000),
		BITBOARD(0x0000000008000000, 0x0000000000000000), BITBOARD(0x0000000010000000, 0x0000000000000000),
		BITBOARD(0x0000000020000000, 0x0000000000000000), BITBOARD(0x0000000040000000, 0x0000000000000000),
		BITBOARD(0x0000000080000000, 0x0000000000000000), BITBOARD(0x0000000100000000, 0x0000000000000000),
		BITBOARD(0x0000000200000000, 0x0000000000000000), BITBOARD(0x0000000400000000, 0x0000000000000000),
		BITBOARD(0x0000000800000000, 0x0000000000000000), BITBOARD(0x0000001000000000, 0x0000000000000000),
		BITBOARD(0x0000002000000000, 0x0000000000000000), BITBOARD(0x0000004000000000, 0x0000000000000000),
		BITBOARD(0x0000008000000000, 0x0000000000000000), BITBOARD(0x0000010000000000, 0x0000000000000000),
		BITBOARD(0x0000020000000000, 0x0000000000000000), BITBOARD(0x0000040000000000, 0x0000000000000000),
		BITBOARD(0x0000080000000000, 0x0000000000000000), BITBOARD(0x0000100000000000, 0x0000000000000000),
		BITBOARD(0x0000200000000000, 0x0000000000000000), BITBOARD(0x0000400000000000, 0x0000000000000000),
		BITBOARD(0x0000800000000000, 0x0000000000000000), BITBOARD(0x0001000000000000, 0x0000000000000000),
		BITBOARD(0x0002000000000000, 0x0000000000000000), BITBOARD(0x0004000000000000, 0x0000000000000000),
		BITBOARD(0x0008000000000000, 0x0000000000000000), BITBOARD(0x0010000000000000, 0x0000000000000000),
		BITBOARD(0x0020000000000000, 0x0000000000000000), BITBOARD(0x0040000000000000, 0x0000000000000000),
		BITBOARD(0x0080000000000000, 0x0000000000000000), BITBOARD(0x0100000000000000, 0x0000000000000000),
		BITBOARD(0x0200000000000000, 0x0000000000000000), BITBOARD(0x0400000000000000, 0x0000000000000000),
		BITBOARD(0x0800000000000000, 0x0000000000000000), BITBOARD(0x1000000000000000, 0x0000000000000000),
		BITBOARD(0x2000000000000000, 0x0000000000000000), BITBOARD(0x4000000000000000, 0x0000000000000000),
		BITBOARD(0x8000000000000000, 0x0000000000000000), BITBOARD(0x0000000000000000, 0x0000000000000001),
		BITBOARD(0x0000000000000000, 0x0000000000000002), BITBOARD(0x0000000000000000, 0x0000000000000004),
		BITBOARD(0x0000000000000000, 0x0000000000000008), BITBOARD(0x0000000000000000, 0x0000000000000010),
		BITBOARD(0x0000000000000000, 0x0000000000000020), BITBOARD(0x0000000000000000, 0x0000000000000040),
		BITBOARD(0x0000000000000000, 0x0000000000000080), BITBOARD(0x0000000000000000, 0x0000000000000100),
		BITBOARD(0x0000000000000000, 0x0000000000000200), BITBOARD(0x0000000000000000, 0x0000000000000400),
		BITBOARD(0x0000000000000000, 0x0000000000000800), BITBOARD(0x0000000000000000, 0x0000000000001000),
		BITBOARD(0x0000000000000000, 0x0000000000002000), BITBOARD(0x0000000000000000, 0x0000000000004000),
		BITBOARD(0x0000000000000000, 0x0000000000008000), BITBOARD(0x0000000000000000, 0x0000000000010000),
		BITBOARD(0x0000000000000000, 0x0000000000020000), BITBOARD(0x0000000000000000, 0x0000000000040000),
		BITBOARD(0x0000000000000000, 0x0000000000080000), BITBOARD(0x0000000000000000, 0x0000000000100000),
		BITBOARD(0x0000000000000000, 0x0000000000200000), BITBOARD(0x0000000000000000, 0x0000000000400000),
		BITBOARD(0x0000000000000000, 0x0000000000800000), BITBOARD(0x0000000000000000, 0x0000000001000000),
		BITBOARD(0x0000000000000000, 0x0000000002000000), BITBOARD(0x0000000000000000, 0x0000000004000000),
		BITBOARD(0x0000000000000000, 0x0000000008000000), BITBOARD(0x0000000000000000, 0x0000000010000000),
		BITBOARD(0x0000000000000000, 0x0000000020000000), BITBOARD(0x0000000000000000, 0x0000000040000000),
		BITBOARD(0x0000000000000000, 0x0000000080000000), BITBOARD(0x0000000000000000, 0x0000000100000000),
		BITBOARD(0x0000000000000000, 0x0000000200000000), BITBOARD(0x0000000000000000, 0x0000000400000000),
		BITBOARD(0x0000000000000000, 0x0000000800000000), BITBOARD(0x0000000000000000, 0x0000001000000000),
		BITBOARD(0x0000000000000000, 0x0000002000000000), BITBOARD(0x0000000000000000, 0x0000004000000000),
		BITBOARD(0x0000000000000000, 0x0000008000000000), BITBOARD(0x0000000000000000, 0x0000010000000000),
		BITBOARD(0x0000000000000000, 0x0000020000000000), BITBOARD(0x0000000000000000, 0x0000040000000000),
		BITBOARD(0x0000000000000000, 0x0000080000000000), BITBOARD(0x0000000000000000, 0x0000100000000000),
		BITBOARD(0x0000000000000000, 0x0000000000000000), BITBOARD(0x0000000000000000, 0x0000000000000000)
	};


	const U8 Rank_Shift_Right[10] = {
		20,29,38,47,56, 1,10,19,28,37
	};
	const U8 Rank_Shift_Left[10] = {
		0,9,18,27,36,45,54,63,72,81
	};

	const S8 Knight_Legal_Leg[40] = {
		0,  -9,   0,  -9,   0,   0,   0,   0,   0,  -1,
		0,   0,   0,   1,   0,   0,   0,   0,   0,   0,
		0,   0,   0,   0,   0,   0,   0,  -1,   0,   0,
		0,   1,   0,   0,   0,   0,   0,   9,   0,   9,
	};

	const UINT64 FileMagic[9] = {
		0x081024080088100cULL,0x1006284400404801ULL,0x0810807200301001ULL,
		0x0088010004980810ULL,0x0281001101080088ULL,0x2420808041040308ULL,
		0x0040050120008085ULL,0x0420278308008022ULL,0x2911110114008021ULL,
	};
	const UINT64 RankMagic[10] = {
		0x000564600003a041ULL,0x0081822102000000ULL,0x0001000000080000ULL,
		0x0000030011800400ULL,0x0000010000000002ULL,0xc100001181113000ULL,
		0x48008000001000c1ULL,0x1801220400009810ULL,0x048130406002008aULL,
		0x0000000021020200ULL,
	};

	const UINT64 BishopMagic[14] = {
		0x00020028a2000142ULL,0x0001800208101404ULL,0x0000000420005000ULL,
		0x00c8004040001880ULL,0x0000030008040400ULL,0x00000004000c2000ULL,
		0x0020003000001089ULL,0x0038088a00001090ULL,0x0000a00004c24060ULL,
		0x10200a0403488008ULL,0x1021010082010504ULL,0x200910002002010cULL,
		0x0000d05201000010ULL,0x0880020084010000ULL,
	};
	const UINT64 KnightMagic[90] = {
		0x1000420410000021ULL,0x10200c4200002000ULL,0x23000b8100008000ULL,
		0x3420044020000000ULL,0x2050113920010080ULL,0x0202410811018044ULL,
		0x0960008912000001ULL,0x0800a01d08104310ULL,0x8102001001010400ULL,
		0x0000004207402080ULL,0x8020080041400000ULL,0x1000002a49240000ULL,
		0x6080a04042810900ULL,0x00000024204000a7ULL,0x009080001008002fULL,
		0x0000002089040001ULL,0x0c20008014060008ULL,0x2000000104808080ULL,
		0x6000900428804040ULL,0x0080100400502800ULL,0x29084450d0804004ULL,
		0x24010404804008c0ULL,0x0440400040a01408ULL,0x00240004421218c2ULL,
		0x0110202058040808ULL,0x000000334228040dULL,0x0000001004894200ULL,
		0x0040084001388024ULL,0x100a000802012810ULL,0x84b1100000864308ULL,
		0x42002001a2247060ULL,0x2000001000400c08ULL,0x420000008021044aULL,
		0x2108000880040604ULL,0x0204000001015402ULL,0x001100000500810dULL,
		0x20040400050a2014ULL,0x4528080000022260ULL,0x2000084221802011ULL,
		0x08a0882028030890ULL,0x04200a00c0844408ULL,0x00c0002160000834ULL,
		0x8088020002000801ULL,0x0105054000400102ULL,0x8020000000109051ULL,
		0x21290a1000001040ULL,0x08140000c0000018ULL,0x9028400800100148ULL,
		0x0402081000099060ULL,0x2482008112002810ULL,0x2d01800090002088ULL,
		0x0f00604092001012ULL,0x0208b05034102081ULL,0x00c0080120000201ULL,
		0x2004140050000080ULL,0x1010832002000204ULL,0x1008058200000820ULL,
		0x8844008100840022ULL,0x0402084020084500ULL,0xa100810105004141ULL,
		0x0180408010000000ULL,0x01108010000c4000ULL,0x2080101102541000ULL,
		0x004c8c0424181010ULL,0x0028420100001024ULL,0x10c2040220040300ULL,
		0x4802010602500200ULL,0x0013844880022000ULL,0x5002834080800000ULL,
		0x0090b04060020202ULL,0x000080a231000480ULL,0x1400442402100010ULL,
		0x4020110101812020ULL,0x0b00050200000290ULL,0x0010814880010010ULL,
		0x98001112c0128010ULL,0x40500a0844141008ULL,0x0102802040020201ULL,
		0x06c6154584100000ULL,0x0101201108000160ULL,0x0000002209000000ULL,
		0x1202000804000020ULL,0x404000a201400000ULL,0x10030000810d1c00ULL,
		0x00100000804080c0ULL,0x4809000280401000ULL,0x0020000020c40000ULL,
		0x0000008210180d00ULL,0x0120020008300000ULL,0x6328000102078100ULL,
	};
	const UINT64 ByKnightMagic[90] = {
		0x8020020501200000ULL,0x1070008302022040ULL,0x4141081900080800ULL,
		0x0000000220000004ULL,0x4100022920063000ULL,0x0824042030180028ULL,
		0x04ba004288020c41ULL,0x290000040c002020ULL,0x06c8004004000400ULL,
		0x14408a4000800010ULL,0x0512888004402808ULL,0x0240850200808302ULL,
		0x0402011030a00808ULL,0xb420804006200000ULL,0x200400c000080020ULL,
		0x0010282080042000ULL,0x00a0124444023001ULL,0x0404401401041003ULL,
		0x0240008244804022ULL,0x0100c40104078003ULL,0x8030200891004080ULL,
		0x0000088080001050ULL,0x040100c0c0810800ULL,0x00002042b1206824ULL,
		0x5000080090080880ULL,0x0c41060048400500ULL,0x100000020d008480ULL,
		0x00020040420084a5ULL,0x1000040d00800140ULL,0x0080000281428220ULL,
		0x0380000010200030ULL,0x8648021400108008ULL,0x0200008020093004ULL,
		0x0128038800620001ULL,0x0400000608521001ULL,0x4002004000012852ULL,
		0x2000002000003001ULL,0xa000000000014400ULL,0x086080010002c000ULL,
		0x1400200090082006ULL,0x3400080080804840ULL,0x0100000228400840ULL,
		0x008081020f800c44ULL,0x4444010003082200ULL,0x822018a000905166ULL,
		0x0808000000004080ULL,0x0088414060810040ULL,0x0004004402000120ULL,
		0x04c400003a008018ULL,0x0008880124000004ULL,0x008080100824022cULL,
		0x00a8824101000041ULL,0x0082200880400421ULL,0x0000200000000a05ULL,
		0x082008000000c924ULL,0x60080c0001000006ULL,0x110102061c027c00ULL,
		0x0400220110200008ULL,0x1100048008804800ULL,0x02000311a8008110ULL,
		0x010008a000002810ULL,0x0480801001008400ULL,0x0840910800040800ULL,
		0x101040020a000020ULL,0x4508000c0000000bULL,0x00080003000080c0ULL,
		0x3182030100189000ULL,0x0802000242000000ULL,0x0882200240000201ULL,
		0x0288490020200100ULL,0x0840208010000002ULL,0x0500202020010844ULL,
		0x4100021503044001ULL,0xa100044202300400ULL,0x2240020001000880ULL,
		0x8040020000c00180ULL,0x0000010080201000ULL,0x0000028280100020ULL,
		0x0000c48a08104082ULL,0x8040201000480004ULL,0x040100a004040000ULL,
		0x0804000400409a00ULL,0x40005050c0084000ULL,0x0302040100020000ULL,
		0x8c06204240108000ULL,0x0828c00882080804ULL,0x00110000c4000003ULL,
		0x1082050248121420ULL,0x0008014922000000ULL,0x013000000420080cULL,
	};


	int piece_from_char(int c)
	{
		if (c >= 0 && c < 128)
			return PieceFromChar[c];
		return 0;
	}

	int piece_to_char(int p)
	{
		if (p <=0 || p >= 16)
			return 0;
		return PieceString[p];

	}
	static INT file_from_char(INT c)
	{
		return File_I - (c - 'a');
	}

	static INT rank_from_char(INT c)
	{
		return Rank_0 + (c - '0');
	}

	static INT file_to_char(INT file)
	{
		return 'i' - (file - File_A);
	}

	static INT rank_to_char(INT rank)
	{
		return '0' + (rank - Rank_0);
	}

	void square_to_string(int sq, char string[])
	{
		string[0] = file_to_char(sq_file(sq));
		string[1] = rank_to_char(sq_rank(sq));
		string[2] = '\0';
	}

	int square_from_string(const char string[])
	{
		int file, rank;

		if (string[0] < 'a' || string[0] > 'i')
			return SQ_End;
		if (string[1] < '0' || string[1] > '9')
			return SQ_End;
		if (string[2] != '\0')
			return SQ_End;

		file = file_from_char(string[0]);
		rank = rank_from_char(string[1]);

		return sq_make(rank,file);
	}


	void move_to_string(int move, char string[])
	{
		square_to_string(move_from(move), &string[0]);
		square_to_string(move_to(move), &string[2]);
	}

	int move_from_string(const char string[])
	{
		char tmp_string[3];
		int from, to;
		int move;

		tmp_string[0] = string[0];
		tmp_string[1] = string[1];
		tmp_string[2] = '\0';

		from = square_from_string(tmp_string);
		if (from < 0)
			return MoveNone;

		tmp_string[0] = string[2];
		tmp_string[1] = string[3];
		tmp_string[2] = '\0';

		to = square_from_string(tmp_string);
		if (to < 0)
			return MoveNone;

		move = move_make(from, to);

		return move;
	}

	const int Rank_Inc[2] = {-9,9};
	const int File_Inc[2] = {-1,1};
	const int Knight_Inc[8] = {-19,-17,-11,-7, 7,11,17,19};
	const int Knight_Leg_Inc[8] = {-9, -9, -1, 1, -1, 1, 9, 9};
	const int Knight_Leged_Inc[8] = {-10, -8, -10, -8, 8, 10, 8, 10};
	const int BishopInc[4] = {-20, -16, 16, 20};
	const int AdvisorInc[4] = {-10,-8,8,10};

	static int sq_distance(int sq1, int sq2);
	static BITBOARD ix_2_bb(int ix, const BITBOARD& mask);

	static BITBOARD rank_block_mask(int sq);
	static BITBOARD file_block_mask(int sq);
	static BITBOARD knight_block_mask(int sq);
	static BITBOARD bishop_block_mask(int sq);
	static BITBOARD knight_attd_mask(int sq);

	static BITBOARD rook_rank_att(int sq, const BITBOARD& block);
	static BITBOARD cannon_rank_att(int sq, const BITBOARD& block);
	static BITBOARD super_rank_att(int sq, const BITBOARD& block);
	static BITBOARD rook_file_att(int sq, const BITBOARD& block);
	static BITBOARD cannon_file_att(int sq, const BITBOARD& block);
	static BITBOARD super_file_att(int sq, const BITBOARD& block);

	static BITBOARD rook_rank_att(int sq, const U16 rank_bit);
	static BITBOARD cannon_rank_att(int sq, const U16 rank_bit);
	static BITBOARD knight_rank_att(int sq, const U16 rank_bits);
	static BITBOARD rook_file_att(int sq, const U16 file_bit);
	static BITBOARD cannon_file_att(int sq, const U16 file_bit);
	static BITBOARD knight_file_att(int sq, const U16 rank_bits);

	static BITBOARD knight_att(int sq, const BITBOARD& block);
	static BITBOARD bishop_att(int sq, const BITBOARD& block);
	static BITBOARD knight_attd(int sq, const BITBOARD& block);

	static BITBOARD pawn_att(int sq, int color);
	static BITBOARD pawn_attd(int sq, int color);
	static BITBOARD advisor_att(int sq);
	static BITBOARD king_att(int sq);

	static void magic_attack_init();
	static void base_attack_init();
	static void check_attack();

	void attack_init()
	{
		base_attack_init();
		magic_attack_init();
	}

	static void check_attack()
	{
		int bits;
		BITBOARD mask, block, attack;
		for (int sq = 0; sq < 90; ++sq)
		{
			mask = rank_block_mask(sq);
			bits = mask.count_bits();
			for (int i = 0; i < (1 << bits); ++i)
			{
				block = ix_2_bb(i, mask);
			}
			mask = file_block_mask(sq);
			bits = mask.count_bits();
			for (int i = 0; i < (1 << bits); ++i)
			{
				block = ix_2_bb(i, mask);
			}
			mask = knight_block_mask(sq);
			bits = mask.count_bits();
			for (int i = 0; i < (1 << bits); ++i)
			{
				block = ix_2_bb(i, mask);
			}
			mask = knight_attd_mask(sq);
			bits = mask.count_bits();
			for (int i = 0; i < (1 << bits); ++i)
			{
				block = ix_2_bb(i, mask);
			}

			if (is_bishop_pos(sq))
			{
				mask = bishop_block_mask(sq);
				bits = mask.count_bits();
				for (int i = 0; i < (1 << bits); ++i)
				{
					block = ix_2_bb(i, mask);
				}
			}
		}
	}

	static void base_attack_init()
	{
		for (int r = 0; r <= Rank_9; ++r)
		{
			BITBOARD bb(0ULL, 0ULL);
			for (int f = 0; f <= File_I; ++f)
			{
				bb.set_bit(sq_make(r, f));
			}
			Rank_Mask[r] = bb;
		}
		for (int f = 0; f <= File_I; ++f)
		{
			BITBOARD bb(0ULL, 0ULL);
			for (int r = 0; r <= Rank_9; ++r)
			{
				bb.set_bit(sq_make(r, f));
			}
			File_Mask[f] = bb;
		}
		//
		for (int r = 0; r <= Rank_9; ++r)
		{
			BITBOARD bb(0ULL, 0ULL);
			for (int i = r - 1; i >= Rank_0; --i)
			{
				bb |= Rank_Mask[i];
			}
			Up_Down_Mask[r][0] = bb;
			bb = BITBOARD(0, 0);
			for (int i = r + 1; i <= Rank_9; ++i)
			{
				bb |= Rank_Mask[i];
			}
			Up_Down_Mask[r][1] = bb;
		}
		for (int f = 0; f <= File_I; ++f)
		{
			BITBOARD bb(0ULL, 0ULL);
			for (int i = f - 1; i >= File_A; --i)
			{
				bb |= File_Mask[i];
			}
			Left_Right_Mask[f][0] = bb;
			bb = BITBOARD(0, 0);
			for (int i = f + 1; i <= File_I; ++i)
			{
				bb |= File_Mask[i];
			}
			Left_Right_Mask[f][1] = bb;
		}

		for (int r1 = 0; r1 <= Rank_9; ++r1)
		{
			for (int r2 = 0; r2 <= Rank_9; ++r2)
			{
				BITBOARD bb(0ULL, 0ULL);
				for (int i = Min(r1, r2)+1; i < Max(r1, r2); ++i)
				{
					bb |= Rank_Mask[i];
				}
				File_Between_Mask[r1][r2] = bb;
			}
		}
		for (int f1 = 0; f1 <= File_I; ++f1)
		{
			for (int f2 = 0; f2 <= File_I; ++f2)
			{
				BITBOARD bb(0ULL, 0ULL);
				for (int i = Min(f1, f2)+1; i < Max(f1, f2); ++i)
				{
					bb |= File_Mask[i];
				}
				Rank_Between_Mask[f1][f2] = bb;
			}
		}

		for (int sq = 0; sq < 90; sq++)
		{
			if (is_king_pos(sq))
			{
				King_Att[king_pos_index(sq)] = king_att(sq);
			}
			if (is_advisor_pos(sq))
			{
				Advisor_Att[advisor_pos_index(sq)] = advisor_att(sq);
			}
			if (is_bishop_pos(sq))
			{
				Bishop_Att_No_Mask[bishop_pos_index(sq)] = bishop_att(sq, BITBOARD(0ULL,0ULL));
			}
			Pawn_Att[sq][White] = pawn_att(sq, White);
			Pawn_Att[sq][Black] = pawn_att(sq, Black);
			Attd_Pawn[sq][White] = pawn_attd(sq, White);
			Attd_Pawn[sq][Black] = pawn_attd(sq, Black);
			Knight_Att_No_Mask[sq] = knight_att(sq, BITBOARD(0ULL,0ULL));
		}
	}

	void magic_attack_init()
	{
		int index, sq, bits;
		BITBOARD mask, attack;

		for (int f = 0; f <= File_I; ++f)
		{
			File_Block_Mask[f] = file_block_mask(sq_make(Rank_0, f));
			bits = File_Block_Mask[f].count_bits();
			for (int r = 0; r <= Rank_9; r++)
			{
				sq = sq_make(r, f);
				for (int i = 0; i < (1 << bits); ++i)
				{
					mask = ix_2_bb(i, File_Block_Mask[f]);
					index = int((mask * FileMagic[f]) >> File_Shift);
					Rook_File_Att_Table[sq][index] =  rook_file_att(sq, mask);
					Cannon_File_Att_Table[sq][index] = cannon_file_att(sq, mask);
				}
			}
		}
		for (int r = 0; r <= Rank_9; r++)
		{
			Rank_Block_Mask[r] = rank_block_mask(sq_make(r, File_A));
			bits = Rank_Block_Mask[r].count_bits();
			for (int f = 0; f <= File_I; f++)
			{
				sq = sq_make(r, f);
				for (int i = 0; i < (1 << bits); ++i)
				{
					mask = ix_2_bb(i, Rank_Block_Mask[r]);
					index = int(mask[sq_color(sq)] >> Rank_Shift_Right[r]) & 127;
					Rook_Rank_Att_Table[sq][index] = rook_rank_att(sq, mask);
					Cannon_Rank_Att_Table[sq][index] = cannon_rank_att(sq, mask);
				}
			}
		}

		for (sq = 0; sq < 90; ++sq)
		{
			Knight_Block_Mask[sq] = knight_block_mask(sq);
			bits = Knight_Block_Mask[sq].count_bits();
			for (int i = 0; i < (1 << bits); ++i)
			{
				mask = ix_2_bb(i, Knight_Block_Mask[sq]);
				attack = knight_att(sq, mask);
				index = int((mask * KnightMagic[sq]) >>(Knight_Shift));
				Knight_Att_BB[sq][index] = attack;
			}

			Knight_Attd_Mask[sq] = knight_attd_mask(sq);
			bits = Knight_Attd_Mask[sq].count_bits();
			for (int i = 0; i < (1 << bits); ++i)
			{
				mask = ix_2_bb(i, Knight_Attd_Mask[sq]);
				attack = knight_attd(sq, mask);
				index = int((mask * ByKnightMagic[sq]) >>(Knight_Shift));
				Knight_Attd_BB[sq][index] = attack;
			}
			if (is_bishop_pos(sq))
			{
				int ix = bishop_pos_index(sq);
				Bishop_Block_Mask[ix] = bishop_block_mask(sq);
				bits = Bishop_Block_Mask[ix].count_bits();
				for (int i = 0; i < (1 << bits); ++i)
				{
					mask = ix_2_bb(i, Bishop_Block_Mask[ix]);
					attack = bishop_att(sq, mask);
					index = int((mask * BishopMagic[ix]) >>(Bishop_Shift));
					Bishop_Att_BB[ix][index] = attack;
				}
			}
		}
	}

	static int sq_distance(int sq1, int sq2)
	{
		return Max(Abs(sq_rank(sq1) - sq_rank(sq2)),Abs(sq_file(sq1) - sq_file(sq2)));
	}

	static BITBOARD ix_2_bb(int index, const BITBOARD& block)
	{
		int i = 0,j;

		BITBOARD mask, rlt(0ULL,0ULL);
		mask = block;

		while (index)
		{
			j = mask.pop_1st();

			if ( index & (1<<i))
			{
				if (j < 64)
				{
					rlt.bits[White] |= 1ULL<<j;
				}
				else
				{
					rlt.bits[Black] |= 1ULL<<(j-64);
				}
				index &= index-1;
			}
			i++;
		}
		return rlt;
	}
	static BITBOARD rank_min_mask(int sq)
	{
		int tmp;
		BITBOARD attack(0ULL,0ULL);
		tmp = sq + File_Inc[0];
		while(sq_is_ok(tmp) && sq_equal_rank(tmp, sq))
		{
			attack.set_bit(tmp);
			tmp += File_Inc[0];
		}
		return attack;
	}
	static BITBOARD file_min_mask(int sq)
	{
		int tmp;
		BITBOARD attack(0ULL,0ULL);
		tmp = sq + Rank_Inc[0];
		while(sq_is_ok(tmp))
		{
			attack.set_bit(tmp);
			tmp += Rank_Inc[0];
		}
		return attack;
	}
	static BITBOARD rank_max_mask(int sq)
	{
		int tmp;
		BITBOARD attack(0ULL,0ULL);
		tmp = sq + File_Inc[1];
		while(sq_is_ok(tmp) && sq_equal_rank(tmp, sq))
		{
			attack.set_bit(tmp);
			tmp += File_Inc[1];
		}
		return attack;
	}
	static BITBOARD file_max_mask(int sq)
	{
		int tmp;
		BITBOARD attack(0ULL,0ULL);
		tmp = sq + Rank_Inc[1];
		while(sq_is_ok(tmp))
		{
			attack.set_bit(tmp);
			tmp += Rank_Inc[1];
		}
		return attack;
	}
	static BITBOARD rook_file_att(int sq, const BITBOARD& block)  
	{
		int tmp;
		BITBOARD attack(0ULL,0ULL);
		for (int i = 0; i < 2; ++i)
		{
			tmp = sq + Rank_Inc[i];
			while(sq_is_ok(tmp))
			{
				attack.set_bit(tmp);
				if (block.check_bit(tmp))
					break;
				tmp += Rank_Inc[i];
			}
		}
		return attack;
	}
	static BITBOARD rook_rank_att(int sq, const BITBOARD& block) 
	{
		int tmp;
		BITBOARD attack(0ULL,0ULL);

		for (int i = 0; i < 2; ++i)
		{
			tmp = sq + File_Inc[i];
			while(sq_is_ok(tmp) && sq_equal_rank(tmp, sq))
			{
				attack.set_bit(tmp);
				if (block.check_bit(tmp))
					break;
				tmp += File_Inc[i];
			}
		}
		return attack;
	}

	static BITBOARD cannon_file_att(int sq, const BITBOARD& block)  
	{
		int tmp;
		BITBOARD attack(0ULL,0ULL);
		for (int i = 0; i < 2; ++i)
		{
			bool find = false;
			tmp = sq + Rank_Inc[i];
			while(sq_is_ok(tmp))
			{
				if (find)
				{
					attack.set_bit(tmp);
					if (block.check_bit(tmp))
						break;
				}
				if (block.check_bit(tmp))
					find = true;
				tmp += Rank_Inc[i];
			}
		}
		return attack;
	}
	static BITBOARD cannon_rank_att(int sq, const BITBOARD& block)  
	{
		int tmp;
		BITBOARD attack(0ULL,0ULL);

		for (int i = 0; i < 2; ++i)
		{
			bool find = false;
			tmp = sq + File_Inc[i];
			while(sq_is_ok(tmp) && sq_equal_rank(tmp, sq))
			{
				if (find)
				{
					attack.set_bit(tmp);
					if (block.check_bit(tmp))
						break;
				}
				if (block.check_bit(tmp))
					find = true;
				tmp += File_Inc[i];
			}
		}
		return attack;
	}

	static BITBOARD knight_att(int sq, const BITBOARD& block)
	{
		INT i,tmp;
		BITBOARD attack(0ULL,0ULL);
		for (i = 0; i < 8; ++i)
		{
			tmp = sq + Knight_Inc[i];
			if (sq_is_ok(tmp) && sq_distance(sq,tmp) <= 2)
			{
				int t = sq + Knight_Leg_Inc[i];
				if (sq_is_ok(t) && !block.check_bit(t))
				{
					attack.set_bit(tmp);
				}
			}
		}	
		return attack;
	}

	static BITBOARD bishop_att(int sq, const BITBOARD& block)
	{
		int i,tmp;
		BITBOARD attack(0ULL,0ULL);

		if (!is_bishop_pos(sq))
			return attack;
		for (i = 0; i < 4; ++i)
		{
			tmp = sq + BishopInc[i];
			if (sq_is_ok(tmp) && is_bishop_pos(tmp))
			{
				if (!block.check_bit((sq+tmp)/2))
				{
					attack.set_bit(tmp);
				}
			}
		}
		return attack;
	}

	static BITBOARD knight_attd(int sq, const BITBOARD& block)
	{
		int i,tmp;
		BITBOARD attack(0ULL,0ULL);
		for (i = 0; i < 8; ++i)
		{
			tmp = sq + Knight_Inc[i];
			if (sq_is_ok(tmp) && sq_distance(sq,tmp) <= 2)
			{
				int t = sq + Knight_Leged_Inc[i];
				if (sq_is_ok(t) && !block.check_bit(t))
				{
					attack.set_bit(tmp);
				}
			}
		}
		return attack;

	}

	static BITBOARD pawn_att(int sq, int color)
	{
		INT tmp;
		BITBOARD attack(0ULL,0ULL);

		if (color == White)
		{
			tmp = sq + 9;
			if (sq_is_ok(tmp))
			{
				attack.set_bit(tmp);
			}
			if (sq >= 45)
			{
				tmp = sq + 1;
				if (sq_is_ok(tmp) && sq_rank(tmp) == sq_rank(sq))
				{
					attack.set_bit(tmp);
				}
				tmp = sq - 1;
				if (sq_is_ok(tmp) && sq_rank(tmp) == sq_rank(sq))
				{
					attack.set_bit(tmp);
				}
			}
		}
		else
		{
			tmp = sq - 9;
			if (sq_is_ok(tmp))
			{
				attack.set_bit(tmp);
			}
			if (sq < 45)
			{
				tmp = sq + 1;
				if (sq_is_ok(tmp) && sq_rank(tmp) == sq_rank(sq))
				{
					attack.set_bit(tmp);
				}
				tmp = sq - 1;
				if (sq_is_ok(tmp) && sq_rank(tmp) == sq_rank(sq))
				{
					attack.set_bit(tmp);
				}
			}
		}
		return attack;
	}
	static BITBOARD pawn_attd(int sq, int color)
	{
		int tmp;
		BITBOARD attack(0ULL,0ULL);

		if (color == Black)
		{
			tmp = sq + 9;
			if (sq_is_ok(tmp))
			{
				attack.set_bit(tmp);
			}
			if (sq < 45)
			{
				tmp = sq + 1;
				if (sq_is_ok(tmp) && sq_rank(tmp) == sq_rank(sq))
				{
					attack.set_bit(tmp);
				}
				tmp = sq - 1;
				if (sq_is_ok(tmp) && sq_rank(tmp) == sq_rank(sq))
				{
					attack.set_bit(tmp);
				}

			}
		}
		else
		{
			tmp = sq - 9;
			if (sq_is_ok(tmp))
			{
				attack.set_bit(tmp);
			}
			if (sq >= 45)
			{
				tmp = sq + 1;
				if (sq_is_ok(tmp) && sq_rank(tmp) == sq_rank(sq))
				{
					attack.set_bit(tmp);
				}
				tmp = sq - 1;
				if (sq_is_ok(tmp) && sq_rank(tmp) == sq_rank(sq))
				{
					attack.set_bit(tmp);
				}
			}
		}
		return attack;
	}
	static BITBOARD advisor_att(int sq)
	{

		INT i,tmp;
		BITBOARD attack(0ULL,0ULL);

		if (!is_advisor_pos(sq))
			return attack;
		for (i = 0; i < 4; ++i)
		{
			tmp = sq + AdvisorInc[i];
			if (sq_is_ok(tmp) && is_advisor_pos(tmp))
			{
				attack.set_bit(tmp);
			}
		}
		return attack;
	}
	static BITBOARD king_att(int sq)
	{
		INT i,tmp;
		BITBOARD attack(0ULL,0ULL);

		if (!is_king_pos(sq))
			return attack;
		for (i = 0; i < 2; ++i)
		{
			tmp = sq + Rank_Inc[i];
			if (sq_is_ok(tmp) && is_king_pos(tmp))
			{
				attack.set_bit(tmp);
			}
		}
		for (i = 0; i < 2; ++i)
		{
			tmp = sq + File_Inc[i];
			if (sq_is_ok(tmp) && is_king_pos(tmp))
			{
				attack.set_bit(tmp);
			}
		}
		return attack;
	}


	static BITBOARD rook_rank_att(int sq, const U16 rank_bit)
	{
		int file = sq_file(sq);
		int rank = sq_rank(sq);
		BITBOARD attack(0ULL,0ULL);

		for (int f = file - 1; f >= File_A; --f)
		{
			attack.set_bit(sq_make(rank,f));
			if ((1 << f) & rank_bit)
				break;
		}
		for (int f = file + 1; f < File_End; ++f)
		{
			attack.set_bit(sq_make(rank,f));
			if ((1 << f) & rank_bit)
				break;
		}
		return attack;
	}
	static BITBOARD cannon_rank_att(int sq, const U16 rank_bit)
	{
		int file = sq_file(sq);
		int rank = sq_rank(sq);
		BITBOARD attack(0ULL,0ULL);

		bool flag = false;
		for (int f = file - 1; f >= File_A; --f)
		{
			if (flag)
			{
				attack.set_bit(sq_make(rank,f));
				if ((1 << f) & rank_bit)
					break;
			}
			if ((1 << f) & rank_bit)
				flag = true;
		}
		flag = false;
		for (int f = file + 1; f < File_End; ++f)
		{
			if (flag)
			{
				attack.set_bit(sq_make(rank,f));
				if ((1 << f) & rank_bit)
					break;
			}
			if ((1 << f) & rank_bit)
				flag = true;
		}

		return attack;
	}
	static BITBOARD knight_rank_att(int sq, const U16 rank_bit)
	{
		int file = sq_file(sq);
		int rank = sq_rank(sq);
		BITBOARD attack(0ULL,0ULL);
		int f = file - 1;
		if (f > File_A)
		{
			if (((1 << f) & rank_bit) == 0)
			{
				if (sq_is_ok(sq - 11) && sq_distance(sq, sq - 11) <= 2)
					attack.set_bit(sq - 11);
				if (sq_is_ok(sq + 7) && sq_distance(sq, sq + 7) <= 2)
					attack.set_bit(sq + 7);
			}
		}
		f = file + 1;
		if (f < File_I)
		{
			if (((1 << f) & rank_bit) == 0)
			{
				if (sq_is_ok(sq + 11))
					attack.set_bit(sq + 11);
				if (sq_is_ok(sq - 7))
					attack.set_bit(sq - 7);
			}
		}
		return attack;
	}
	static BITBOARD rook_file_att(int sq, const U16 file_bit)
	{
		int file = sq_file(sq);
		int rank = sq_rank(sq);
		BITBOARD attack(0ULL,0ULL);

		for (int r = rank - 1; r >= Rank_0; --r)
		{
			attack.set_bit(sq_make(r,file));
			if ((1 << r) & file_bit)
				break;
		}
		for (int r = rank + 1; r < Rank_End; ++r)
		{
			attack.set_bit(sq_make(r,file));
			if ((1 << r) & file_bit)
				break;
		}
		return attack;
	}
	static BITBOARD cannon_file_att(int sq, const U16 file_bit)
	{
		int file = sq_file(sq);
		int rank = sq_rank(sq);
		BITBOARD attack(0ULL,0ULL);

		bool flag = false;

		for (int r = rank - 1; r >= Rank_0; --r)
		{
			if (flag)
			{
				attack.set_bit(sq_make(r,file));
				if ((1 << r) & file_bit)
					break;
			}
			if ((1 << r) & file_bit)
				flag = true;
		}

		flag = false;
		for (int r = rank + 1; r < Rank_End; ++r)
		{
			if (flag)
			{
				attack.set_bit(sq_make(r,file));
				if ((1 << r) & file_bit)
					break;
			}
			if ((1 << r) & file_bit)
				flag = true;
		}
		return attack;
	}

	static BITBOARD knight_file_att(int sq, const U16 file_bit)
	{
		int file = sq_file(sq);
		int rank = sq_rank(sq);
		BITBOARD attack(0ULL,0ULL);
		int r = rank - 1;
		if (r > Rank_0)
		{
			if (((1 << r) & file_bit) == 0)
			{
				if (sq_is_ok(sq - 17) && sq_distance(sq, sq - 17) <= 2)
					attack.set_bit(sq - 17);
				if (sq_is_ok(sq - 19) && sq_distance(sq, sq - 19) <= 2)
					attack.set_bit(sq - 19);
			}
		}
		r = rank + 1;
		if (r < Rank_9)
		{
			if (((1 << r) & file_bit) == 0)
			{
				if (sq_is_ok(sq + 17) && sq_distance(sq, sq + 17) <= 2)
					attack.set_bit(sq + 17);
				if (sq_is_ok(sq + 19) && sq_distance(sq, sq + 19) <= 2)
					attack.set_bit(sq + 19);
			}
		}
		return attack;
	}
	static BITBOARD rank_block_mask(int sq)
	{
		INT tmp;
		BITBOARD mask(0ULL,0ULL);

		tmp = sq + File_Inc[0];//左
		while(tmp >= 0 && sq_rank(tmp) == sq_rank(sq) && sq_file(tmp) > File_A)
		{
			mask.set_bit(tmp);
			tmp += File_Inc[0];
		}

		tmp = sq + File_Inc[1];//右
		while(tmp < 90 && sq_rank(tmp) == sq_rank(sq) && sq_file(tmp) < File_I)
		{
			mask.set_bit(tmp);
			tmp += File_Inc[1];
		}
		return mask;
	}
	static BITBOARD file_block_mask(int sq)
	{
		INT tmp;
		BITBOARD mask(0ULL,0ULL);

		tmp = sq + Rank_Inc[0];//上
		while(tmp >= 0 && sq_rank(tmp) > Rank_0)
		{
			mask.set_bit(tmp);
			tmp += Rank_Inc[0];
		}
		tmp = sq + Rank_Inc[1];//下
		while(tmp < 90 && sq_rank(tmp) < Rank_9)
		{
			mask.set_bit(tmp);
			tmp += Rank_Inc[1];
		}

		return mask;
	}
	static BITBOARD knight_block_mask(int sq)
	{
		INT i,tmp;
		BITBOARD mask(0ULL,0ULL);

		for (i = 0; i < 8; ++i)
		{
			tmp = sq + Knight_Inc[i];

			if (sq_is_ok(tmp) && sq_distance(sq,tmp) <= 2)
			{
				mask.set_bit(sq + Knight_Leg_Inc[i]);
			}
		}
		return mask;
	}
	static BITBOARD bishop_block_mask(int sq)
	{
		INT i,tmp;
		BITBOARD mask(0ULL,0ULL);

		if (!is_bishop_pos(sq))
			return mask;
		for (i = 0; i < 4; ++i)
		{
			tmp = sq + BishopInc[i];
			if (sq_is_ok(tmp) && is_bishop_pos(tmp))
			{
				mask.set_bit((sq + tmp)/2);
			}
		}
		return mask;
	}
	static BITBOARD knight_attd_mask(int sq)
	{
		INT i,tmp;
		BITBOARD mask(0ULL,0ULL);

		for (i = 0; i < 8; ++i)
		{
			tmp = sq + Knight_Inc[i];

			if (sq_is_ok(tmp) && sq_distance(sq,tmp) <= 2)
			{
				mask.set_bit(sq + Knight_Leged_Inc[i]);
			}
		}
		return mask;
	}


	void Position::clear()
	{
		blockers.clear();
		for(int i = 0; i < 16; i++) {
			pieces[i].clear();
		}
		memset(number, 0, sizeof(number));
		memset(square, 0, sizeof(square));
		key = 0;
		stack.clear();
		turn = ColorNone;
	}

	void Position::to_fen(char fen[])const
	{
		int i, n = 0, index = 0;

		for (i = 89; i >= 0; i--)
		{
			if (i % 9 == 8 && i != 89)
			{
				if (n != 0)
				{
					fen[index++] = n + '0';
					n = 0;
				}
				fen[index++] = '/';
			}
			if (square[i] != 0)
			{
				if (n != 0)
				{
					fen[index++] = n + '0';
					n = 0;
				}
				fen[index++] = piece_to_char(square[i]);
			}
			else
				++n;
		}
		if (i == -1 && n != 0)
			fen[index++] = n + '0';
		fen[index++] = ' ';
		if (turn == White)
			fen[index++] = 'w';
		else if (turn == Black)
			fen[index++] = 'b';
		fen[index] = '\0';
	}

	bool Position::from_fen(const char fen[])
	{
		INT i,sq,len;
		INT piece,color;

		clear();
		len = (int)strlen(fen);
		sq = 89;
		for (i = 0; i < len && sq >= 0; ++i)
		{
			if (isdigit(fen[i]))
			{
				sq -= fen[i] - '0';
			}
			else if(isalpha(fen[i]))
			{
				if ((piece = piece_from_char(fen[i])) != 0)
				{
					color = piece_color(piece);
					switch(piece)
					{
						case WhiteKing:
						case BlackKing:
							if (!is_king_pos(sq, color) || number[piece] > 0)
							{
								return false;
							}
							break;
						case WhiteAdvisor:
						case BlackAdvisor:
							if (!is_advisor_pos(sq, color) || number[piece] > 1)
							{
								return false;
							}
							break;
						case WhiteBishop:
						case BlackBishop:
							if (!is_bishop_pos(sq, color) || number[piece] > 1)
							{
								return false;
							}
							break;
						case WhitePawn:
							if(White_Pawn_Pos[sq] < 0 || number[piece] > 4)
							{
								return false;
							}
							break;
						case BlackPawn:
							if(White_Pawn_Pos[sq_rank_mirror(sq)] < 0 || number[piece] > 4)
							{
								return false;
							}
							break;
						case WhiteCannon:
						case BlackCannon:
						case WhiteKnight:
						case BlackKnight:
						case WhiteRook:
						case BlackRook:
							if(number[piece] > 1)
							{
								return false;
							}
							break;
					}
					square[sq] = piece;
					number[piece] ++;
					number[color<<3] ++;
					pieces[piece].set_bit(sq);
					pieces[color<<3].set_bit(sq);
					blockers.set_bit(sq);
				}
				sq --;
			}
		}
		if (sq == -1)
		{
			for (; i < len; i++)
			{
				if (fen[i] == 'W' || fen[i] == 'w' || fen[i] == 'R' || fen[i] == 'r')
				{
					turn = White;
					break;
				}
				else if (fen[i] == 'B' || fen[i] == 'b')
				{
					turn = Black;
					break;
				}
			}
		}
		else
		{
			turn = White;
		}

		if(number[WhiteKing] == 0 || number[BlackKing] == 0)
			return false;

		//key = pos_key();
		return true;
	}

	U64 Position::pos_key()const
	{
		int piece;
		U64 key = 0ULL;

		for (INT i = 0; i < 90; ++i)
		{
			if (piece = square[i])
				key ^= piece_key(piece,i);
		}
		if (turn == White)
			key ^= turn_key();
		return key;
	}

	bool Position::in_check(int me)const
	{
		int opp = color_opp(me);
		int k_pos = king(me);

		if (sq_rank_mask(k_pos)[me] & pieces[piece_make(opp, Rook)][me])
		{
			if (rook_rank_attack_bb(k_pos, blockers)[me] & pieces[piece_make(opp, Rook)][me])
			{
				return true;
			}
		}
		if (sq_rank_mask(k_pos)[me] & pieces[piece_make(opp, Cannon)][me])
		{
			if (cannon_rank_attack_bb(k_pos, blockers)[me] & pieces[piece_make(opp, Cannon)][me])
			{
				return true;
			}
		}
		if (knight_att_no_mask(k_pos)[me] & pieces[piece_make(opp, Knight)][me])
		{
			if (knight_attacked_bb(k_pos, blockers)[me] & pieces[piece_make(opp, Knight)][me])
			{
				return true;
			}
		}
		if (pawn_attacked_bb(k_pos, opp)[me] & pieces[piece_make(opp, Pawn)][me])
		{
			return true;
		}

		if (sq_file_mask(k_pos) & pieces[piece_make(opp, Rook)])
		{
			if (rook_file_attack_bb(k_pos, blockers) & pieces[piece_make(opp, Rook)])
			{
				return true;
			}
		}
		if (sq_file_mask(k_pos) & pieces[piece_make(opp, Cannon)])
		{
			if (cannon_file_attack_bb(k_pos, blockers) & pieces[piece_make(opp, Cannon)])
			{
				return true;
			}
		}
		return false;
	}

	bool Position::is_legal()const
	{
		S8 me_king = king(turn);
		S8 opp_king = king(color_opp(turn));
		if (sq_equal_file(me_king, opp_king) && !(file_between_bb(me_king, opp_king) & blockers))
		{
			return false;
		}
		if (in_check(color_opp(turn)))
		{
			return false;
		}
		return true;
	}

	bool Position::move_is_pseudo(int move)const
	{
		S8 from = move_from(move);
		S8 to = move_to(move);

		if (!sq_is_ok(from) || !sq_is_ok(to) || from == to)
		{
			return false;
		}
		if (square[from] == 0 || piece_color(square[from]) != turn)
		{
			return false;
		}
		if (square[to] && piece_color(square[to]) != color_opp(turn))
		{
			return false;
		}
		switch (sq_piece_type(from))
		{
		case Rook:
			if (sq_equal_rank(from, to))
			{
				if (!(rank_between_bb(from, to) & blockers))
					return true;
			}
			else if (sq_equal_file(from, to))
			{
				if (!(file_between_bb(from, to) & blockers))
					return true;
			}
			break;
		case Cannon:
			if (sq_equal_rank(from,to))
			{
				BITBOARD pin_bb(rank_between_bb(from, to) & blockers);
				if (square[to] == 0)
				{
					if(!pin_bb)
						return true;
				}
				else
				{
					if (pin_bb)
					{
						pin_bb.pop_1st();
						if(!pin_bb)
							return true;
					}
				}
			}
			else if (sq_equal_file(from,to))
			{
				BITBOARD pin_bb(file_between_bb(from, to) & blockers);
				if (square[to] == 0)
				{
					if(!pin_bb)
						return true;
				}
				else
				{
					if (pin_bb)
					{
						pin_bb.pop_1st();
						if(!pin_bb)
							return true;
					}
				}
			}
			break;
		case Knight:
			if(knight_att_no_mask(from) & sq_2_bb(to))
			{
				if (square[knight_legal_leg(from, to)] == 0)
					return true;
			}
			break;
		case Bishop:
			if (is_bishop_pos(from, sq_piece_color(from)) && (bishop_att_no_mask(from) & sq_2_bb(to)) && square[(from+to)>>1] == 0)
			{
				return true;
			}
			break;
		case Advisor:
			if (is_advisor_pos(from, sq_piece_color(from)) && (advisor_attack_bb(from) & sq_2_bb(to)))
			{
				return true;
			}
			break;
		case Pawn:
			if (pawn_attack_bb(from, turn) & sq_2_bb(to))
			{
				return true;
			}
			break;
		case King:
			if (is_king_pos(from, sq_piece_color(from)) && (king_attack_bb(from) & sq_2_bb(to)))
			{
				return true;
			}
			break;
		}
		return false;
	}

	bool Position::pseudo_is_legal(int move)const
	{

		S8 from = move_from(move), to = move_to(move);
		S8 me = sq_piece_color(from);
		S8 opp = color_opp(me);

		if (sq_piece_type(from) == King)
		{//king move.
			if (sq_equal_file(from, to))
			{
				if (sq_rank_mask(to)[me] & piece_bb(opp, Rook)[me])
				{
					if (rook_rank_attack_bb(to, blockers)[me] & piece_bb(opp, Rook)[me])
						return false;
				}
				if (sq_rank_mask(to)[me] & piece_bb(opp, Cannon)[me])
				{
					if (cannon_rank_attack_bb(to, blockers)[me] & piece_bb(opp, Cannon)[me])
						return false;
				}
				if (knight_att_no_mask(to)[me] & piece_bb(opp, Knight)[me])
				{
					if (knight_attacked_bb(to, blockers)[me] & piece_bb(opp, Knight)[me])
						return false;
				}
				if (piece_bb(opp, Pawn)[me])
				{
					if (pawn_attacked_bb(to, opp)[me] & piece_bb(opp, Pawn)[me])
						return false;
				}
				if (square[to])
				{//eat piece
					if (sq_file_mask(to) & (piece_bb(opp, Rook)|piece_bb(opp, King)))
					{
						if (rook_file_attack_bb(to, blockers) & (piece_bb(opp, Rook)|piece_bb(opp, King)))
							return false;
					}
					if (sq_file_mask(to) & piece_bb(opp, Cannon))
					{
						if (cannon_file_attack_bb(to, blockers^sq_2_bb(from)) & piece_bb(opp, Cannon))
							return false;
					}
				}
			}
			else
			{//equal_rank
				if (sq_file_mask(to) & (piece_bb(opp, Rook)|piece_bb(opp, King)))
				{
					if (rook_file_attack_bb(to, blockers) & (piece_bb(opp, Rook)|piece_bb(opp, King)))
						return false;
				}
				if (sq_file_mask(to) & piece_bb(opp, Cannon))
				{
					if (cannon_file_attack_bb(to, blockers) & piece_bb(opp, Cannon))
						return false;
				}
				if (knight_att_no_mask(to)[me] & piece_bb(opp, Knight)[me])
				{
					if (knight_attacked_bb(to, blockers)[me] & piece_bb(opp, Knight)[me])
						return false;
				}
				if (piece_bb(opp, Pawn)[me])
				{
					if (pawn_attacked_bb(to, opp)[me] & piece_bb(opp, Pawn)[me])
						return false;
				}
				if (square[to])
				{//eat piece
					if (sq_rank_mask(to)[me] & piece_bb(opp, Rook)[me])
					{
						if (rook_rank_attack_bb(to, blockers)[me] & piece_bb(opp, Rook)[me])
							return false;
					}
					if (sq_rank_mask(to)[me] & piece_bb(opp, Cannon)[me])
					{
						if (cannon_rank_attack_bb(to, blockers^sq_2_bb(from))[me] & piece_bb(opp, Cannon)[me])
							return false;
					}
				}
			}
		}
		else
		{//not king move.
			S8 king_pos = king(me);
			if (sq_equal_rank(from, king_pos))
			{
				if (sq_equal_rank(from, to))
				{
					if(square[to] == 0)
						return true;
					if (sq_rank_mask(king_pos)[me] & piece_bb(opp, Cannon)[me])
					{
						if (cannon_rank_attack_bb(king_pos, blockers^sq_2_bb(from))[me] & piece_bb(opp, Cannon)[me] & ~(sq_2_bb(to)[me]))
							return false;
					}
					if (sq_piece_type(from) == Cannon && (sq_rank_mask(king_pos)[me] & piece_bb(opp, Rook)[me]))
					{
						if (rook_rank_attack_bb(king_pos, blockers^sq_2_bb(from))[me] & piece_bb(opp, Rook)[me])
							return false;
					}
				}
				else
				{
					if (sq_rank_mask(king_pos)[me] & piece_bb(opp, Rook)[me])
					{
						if (rook_rank_attack_bb(king_pos, blockers^sq_2_bb(from))[me] & piece_bb(opp, Rook)[me])
							return false;
					}
					if (sq_rank_mask(king_pos)[me] & piece_bb(opp, Cannon)[me])
					{
						if (cannon_rank_attack_bb(king_pos, blockers^sq_2_bb(from))[me] & piece_bb(opp, Cannon)[me])
							return false;
					}
				}
			}
			else if(sq_equal_file(from, king_pos))
			{
				if (sq_equal_file(from, to))
				{
					if(square[to] == 0)
						return true;
					if (sq_file_mask(king_pos) & piece_bb(opp, Cannon))
					{
						if (cannon_file_attack_bb(king_pos, blockers^sq_2_bb(from)) & piece_bb(opp, Cannon) & ~sq_2_bb(to))
							return false;
					}
					if (sq_piece_type(from) == Cannon && (sq_file_mask(king_pos) & (piece_bb(opp, Rook)|piece_bb(opp, King))))
					{
						if (rook_file_attack_bb(king_pos, blockers^sq_2_bb(from)) & (piece_bb(opp, Rook)|piece_bb(opp, King)))
							return false;
					}
				}
				else
				{
					if (sq_file_mask(king_pos) & (piece_bb(opp, Rook)|piece_bb(opp, King)))
					{
						if (rook_file_attack_bb(king_pos, blockers^sq_2_bb(from)) & (piece_bb(opp, Rook)|piece_bb(opp, King)))
							return false;
					}
					if (sq_file_mask(king_pos) & piece_bb(opp, Cannon))
					{
						if (cannon_file_attack_bb(king_pos, blockers^sq_2_bb(from)) & piece_bb(opp, Cannon))
							return false;
					}
				}
			}
			else if(is_leg_pos(from, king_pos) && (knight_att_no_mask(king_pos)[me] & piece_bb(opp, Knight)[me]))
			{
				S8 sq;
				U64 bits = knight_att_no_mask(king_pos)[me] & piece_bb(opp, Knight)[me];
				do 
				{
					sq = pop_1st_sq(bits, me);
					if (from == knight_legal_leg(sq, king_pos) && to != sq)
						return false;
				} while (bits != 0);
			}
			if (square[to] == 0)
			{
				if (sq_equal_rank(to, king_pos))
				{
					if (cannon_rank_attack_bb(king_pos, blockers ^ sq_2_bb(to))[me] & piece_bb(opp, Cannon)[me])
						return false;
				}
				else if (sq_equal_file(to, king_pos))
				{
					if (cannon_file_attack_bb(king_pos, blockers ^ sq_2_bb(to)) & piece_bb(opp, Cannon))
						return false;
				}
			}
		}
		return true;
	}

	bool Position::move_is_legal(int move)const
	{
		S8 from = move_from(move);
		S8 to = move_to(move);
		S8 me = sq_piece_color(from);
		S8 opp = color_opp(me);

		if (sq_piece_type(from) == King)
		{
			//king move.
			BITBOARD block(blockers ^ sq_2_bb(from));
			if (pieces[piece_make(opp,Rook)])
			{
				if (sq_rank_mask(to)[me] & piece_bb(opp, Rook)[me])
				{
					if (rook_rank_attack_bb(to, block)[me] & piece_bb(opp, Rook)[me])
						return false;
				}
				if (sq_file_mask(to) & piece_bb(opp, Rook))
				{
					if (rook_file_attack_bb(to, block) & piece_bb(opp, Rook))
						return false;
				}
			}
			if (pieces[piece_make(opp,Cannon)])
			{
				if (sq_rank_mask(to)[me] & piece_bb(opp, Cannon)[me])
				{
					if (cannon_rank_attack_bb(to, block)[me] & piece_bb(opp, Cannon)[me])
						return false;
				}
				if (sq_file_mask(to) & piece_bb(opp, Cannon))
				{
					if (cannon_file_attack_bb(to, block) & piece_bb(opp, Cannon))
						return false;
				}
			}
			if (pieces[piece_make(opp, Knight)])
			{
				if (knight_att_no_mask(to)[me] & piece_bb(opp, Knight)[me])
				{			
					if (knight_attacked_bb(to, block)[me] & piece_bb(opp, Knight)[me])
						return false;
				}
			}
			if (piece_bb(opp, Pawn)[me])
			{
				if (pawn_attacked_bb(to, opp)[me] & piece_bb(opp, Pawn)[me])
					return false;
			}	
			if (sq_equal_file(to, king(opp)))
			{
				if (!(file_between_bb(to, king(opp)) & block))
					return false;
			}
		}
		else
		{
			S8 k_pos = king(me);
			if (square[to])
			{
				BITBOARD block(blockers ^ sq_2_bb(from));
				if (pieces[piece_make(opp,Rook)])
				{
					if (sq_rank_mask(k_pos)[me] & piece_bb(opp, Rook)[me])
					{
						if (rook_rank_attack_bb(k_pos, block)[me] & piece_bb(opp, Rook)[me] & ~sq_2_bb(to)[me])
							return false;
					}
					if (sq_file_mask(k_pos) & piece_bb(opp, Rook))
					{
						if (rook_file_attack_bb(k_pos, block) & piece_bb(opp, Rook) & ~sq_2_bb(to))
							return false;
					}
				}
				if (pieces[piece_make(opp,Cannon)])
				{
					if (sq_rank_mask(k_pos)[me] & piece_bb(opp, Cannon)[me])
					{
						if (cannon_rank_attack_bb(k_pos, block)[me] & piece_bb(opp, Cannon)[me] & ~sq_2_bb(to)[me])
							return false;
					}

					if (sq_file_mask(k_pos) & piece_bb(opp, Cannon))
					{
						if (cannon_file_attack_bb(k_pos, block) & piece_bb(opp, Cannon) & ~sq_2_bb(to))
							return false;
					}
				}
				if (pieces[piece_make(opp, Knight)])
				{	
					if (knight_att_no_mask(k_pos)[me] & piece_bb(opp, Knight)[me])
					{
						if (knight_attacked_bb(k_pos, block)[me] & piece_bb(opp, Knight)[me] & ~sq_2_bb(to)[me])
							return false;
					}
				}
				if (piece_bb(opp, Pawn)[me])
				{
					if (pawn_attacked_bb(k_pos, opp)[me] & piece_bb(opp, Pawn)[me] & ~sq_2_bb(to)[me])
						return false;
				}	
				if (sq_equal_file(k_pos, king(opp)))
				{
					if (!(file_between_bb(k_pos, king(opp)) & block))
						return false;
				}
			}
			else
			{
				BITBOARD block(blockers ^ sq_2_bb(from) ^sq_2_bb(to));

				if (pieces[piece_make(opp,Rook)])
				{
					if (sq_rank_mask(k_pos)[me] & piece_bb(opp, Rook)[me])
					{
						if (rook_rank_attack_bb(k_pos, block)[me] & piece_bb(opp, Rook)[me])
							return false;
					}
					if (sq_file_mask(k_pos) & piece_bb(opp, Rook))
					{
						if (rook_file_attack_bb(k_pos, block) & piece_bb(opp, Rook))
							return false;
					}
				}
				if (pieces[piece_make(opp,Cannon)])
				{
					if (sq_rank_mask(k_pos)[me] & piece_bb(opp, Cannon)[me])
					{
						if (cannon_rank_attack_bb(k_pos, block)[me] & piece_bb(opp, Cannon)[me])
							return false;
					}
					if (sq_file_mask(k_pos) & piece_bb(opp, Cannon))
					{
						if (cannon_file_attack_bb(k_pos, block) & piece_bb(opp, Cannon))
							return false;
					}
				}
				if (pieces[piece_make(opp,Knight)])
				{
					if (knight_att_no_mask(k_pos)[me] & piece_bb(opp, Knight)[me])
					{
						if (knight_attacked_bb(k_pos, block)[me] & piece_bb(opp, Knight)[me])
							return false;
					}
				}
				if (piece_bb(opp, Pawn)[me])
				{
					if (pawn_attacked_bb(k_pos, opp)[me] & piece_bb(opp, Pawn)[me])
						return false;
				}	
				if (sq_equal_file(k_pos, king(opp)))
				{
					if (!(file_between_bb(k_pos, king(opp)) & block))
						return false;
				}
			}
		}
		return true;
	}

	void Position::move_do(int move)
	{
		int ply = stack.size();
		S8 piece = square[move_from(move)];
		S8 cap = square[move_to(move)];
		S8 from = move_from(move);
		S8 to = move_to(move);
		BITBOARD bb(bb_set(from)^bb_set(to));

		blockers ^= bb;
		pieces[turn<<3] ^= bb;
		pieces[piece] ^= bb;
		stack.resize(ply+1);
		stack[ply].lock = key;
		stack[ply].move = move;
		stack[ply].cap = cap;
		stack[ply].check = false;

		if (cap != 0)
		{
			blockers ^= bb_set(to);
			pieces[(turn^1)<<3] ^= bb_set(to);
			pieces[cap] ^= bb_set(to);

			number[cap] --;
			number[(turn^1)<<3] --;
			key ^= piece_key(cap, to);
		}

		square[from] = 0;
		square[to] = piece;	

		//判断是否将军
		S8 k_pos = king(turn^1);
		if (piece_type(piece) == King)
		{
			if (sq_equal_file(from, k_pos) && sq_equal_rank(from, to) && sq_file_mask(k_pos) & piece_bb(turn, Cannon))
			{
				if (cannon_file_attack_bb(k_pos, blockers) & piece_bb(turn, Cannon))
				{
					stack[ply].check = true;
				}
			}
		}
		else
		{
			if (sq_equal_rank(from, k_pos))
			{
				if (sq_equal_rank(from, to))
				{
					if (piece_type(piece) == Pawn)
					{
						if (pawn_attacked_bb(k_pos, turn) & piece_bb(turn, Pawn))
						{
							stack[ply].check = true;
							goto Finish;
						}
					}
					if (cap == 0)
						goto Finish;
					if (piece_type(piece) == Rook)
					{
						if (!(rank_between_bb(to, k_pos) & blockers))
							stack[ply].check = true;
					}
					else if (piece_type(piece) == Pawn)
					{
						if (sq_rank_mask(k_pos) & piece_bb(turn, Cannon))
						{
							if (cannon_rank_attack_bb(k_pos, blockers) & piece_bb(turn, Cannon))
							{
								stack[ply].check = true;
								goto Finish;
							}
						}
					}
					else if (piece_type(piece) == Cannon)
					{
						if (cannon_rank_attack_bb(k_pos, blockers) & piece_bb(turn, Cannon))
						{
							stack[ply].check = true;
							goto Finish;
						}
						if (sq_rank_mask(k_pos) & piece_bb(turn, Rook))
						{
							if (rook_rank_attack_bb(k_pos, blockers) & piece_bb(turn, Rook))
							{
								stack[ply].check = true;
								goto Finish;
							}
						}
					}
					goto Finish;
				}
				if (sq_rank_mask(k_pos) & piece_bb(turn, Cannon))
				{
					if (cannon_rank_attack_bb(k_pos, blockers) & piece_bb(turn, Cannon))
					{
						stack[ply].check = true;
						goto Finish;
					}
				}
				if (sq_rank_mask(k_pos) & piece_bb(turn, Rook))
				{
					if (rook_rank_attack_bb(k_pos, blockers) & piece_bb(turn, Rook))
					{
						stack[ply].check = true;
						goto Finish;
					}
				}
			}
			if (sq_equal_file(from, k_pos))
			{
				if (sq_equal_file(from, to))
				{
					if (piece_type(piece) == Pawn)
					{
						if (pawn_attacked_bb(k_pos, turn) & piece_bb(turn, Pawn))
						{
							stack[ply].check = true;
							goto Finish;
						}
					}
					if (cap == 0)
						goto Finish;
					if (piece_type(piece) == Rook)
					{
						if (!(file_between_bb(to, k_pos) & blockers))
							stack[ply].check = true;
					}
					else if (piece_type(piece) == Pawn)
					{
						if (sq_file_mask(k_pos) & piece_bb(turn, Cannon))
						{
							if (cannon_file_attack_bb(k_pos, blockers) & piece_bb(turn, Cannon))
							{
								stack[ply].check = true;
								goto Finish;
							}
						}
					}
					else if (piece_type(piece) == Cannon)
					{
						if (cannon_file_attack_bb(k_pos, blockers) & piece_bb(turn, Cannon))
						{
							stack[ply].check = true;
							goto Finish;
						}
						if (sq_file_mask(k_pos) & piece_bb(turn, Rook))
						{
							if (rook_file_attack_bb(k_pos, blockers) & piece_bb(turn, Rook))
							{
								stack[ply].check = true;
								goto Finish;
							}
						}
					}
					goto Finish;
				}
				if (sq_file_mask(k_pos) & piece_bb(turn, Cannon))
				{
					if (cannon_file_attack_bb(k_pos, blockers) & piece_bb(turn, Cannon))
					{
						stack[ply].check = true;
						goto Finish;
					}
				}
				if (sq_file_mask(k_pos) & piece_bb(turn, Rook))
				{
					if (rook_file_attack_bb(k_pos, blockers) & piece_bb(turn, Rook))
					{
						stack[ply].check = true;
						goto Finish;
					}
				}
			}

			if (is_leg_pos(from, k_pos) && (knight_att_no_mask(k_pos) & piece_bb(turn, Knight)))
			{
				if (knight_attacked_bb(k_pos, blockers) & piece_bb(turn, Knight))
				{
					stack[ply].check = true;
					goto Finish;
				}
			}
			if (sq_equal_rank(to, k_pos))
			{
				if (piece_type(piece) == Rook)
				{
					if (!(rank_between_bb(to, k_pos) & blockers))
						stack[ply].check = true;
					goto Finish;
				}
				if (piece_type(piece) == Pawn)
				{
					if (pawn_attacked_bb(k_pos, turn) & piece_bb(turn, Pawn))
					{
						stack[ply].check = true;
						goto Finish;
					}
				}
				else if (piece_type(piece) == Cannon)
				{
					if ((rank_between_bb(to, k_pos) & blockers).only_1_bit_set())
					{
						stack[ply].check = true;
						goto Finish;
					}
				}
				if (cap == 0 && (sq_rank_mask(k_pos) & piece_bb(turn, Cannon)))
				{
					if (cannon_rank_attack_bb(k_pos, blockers) & piece_bb(turn, Cannon))
					{
						stack[ply].check = true;
						goto Finish;
					}
				}
				goto Finish;
			}
			if (sq_equal_file(to, k_pos))
			{
				if (piece_type(piece) == Rook)
				{
					if (!(file_between_bb(to, k_pos) & blockers))
						stack[ply].check = true;
					goto Finish;
				}
				if (piece_type(piece) == Pawn)
				{
					if (pawn_attacked_bb(k_pos, turn) & piece_bb(turn, Pawn))
					{
						stack[ply].check = true;
						goto Finish;
					}
				}
				else if (piece_type(piece) == Cannon)
				{
					if ((file_between_bb(to, k_pos) & blockers).only_1_bit_set())
					{
						stack[ply].check = true;
						goto Finish;
					}
				}
				if (cap == 0 && (sq_file_mask(k_pos) & piece_bb(turn, Cannon)))
				{
					if (cannon_file_attack_bb(k_pos, blockers) & piece_bb(turn, Cannon))
					{
						stack[ply].check = true;
						goto Finish;
					}
				}
				goto Finish;
			}
			if (piece_type(piece) == Knight)
			{
				if (knight_att_no_mask(k_pos) & sq_2_bb(to))
				{
					if (square[knight_legal_leg(to, k_pos)] == 0)
					{
						stack[ply].check = true;
						goto Finish;
					}
				}
			}
		}

Finish:
		key ^= piece_key(piece, from)^piece_key(piece, to)^turn_key();
		turn ^= 1;
	}
	void Position::move_undo()
	{
		int ply = stack.size();
		U16 move = stack[ply-1].move;
		S8 cap = stack[ply-1].cap;
		S8 from = move_from(move); 
		S8 to = move_to(move);
		S8 piece = square[to];
		BITBOARD bb(bb_set(from) ^ bb_set(to));

		blockers ^= bb;
		pieces[(turn^1)<<3] ^= bb;
		pieces[piece] ^= bb;
		square[from] = piece;
		square[to] = cap;
		if (cap != 0)
		{
			blockers ^= bb_set(to);
			pieces[turn<<3] ^= bb_set(to);
			pieces[cap] ^= bb_set(to);
			number[cap] ++;
			number[turn<<3] ++;
			key ^= piece_key(cap, to);
		}
		key ^= piece_key(piece, from)^piece_key(piece, to)^turn_key();
		turn ^= 1;
		stack.resize(ply-1);
	}


	void Position::rep_move_do(int move)
	{
		register INT8 from = move_from(move);
		register INT8 to = move_to(move);
		register INT8 color = sq_piece_color(from);
		register BITBOARD bb = sq_2_bb(from) ^ sq_2_bb(to);

		pieces[square[from]] ^= bb;
		pieces[color<<3] ^= bb;
		blockers ^= bb;

		square[to] = square[from];
		square[from] = 0;
	}
	void Position::rep_move_undo(int move)
	{
		register INT8 from = move_from(move);
		register INT8 to = move_to(move);
		register INT8 color = sq_piece_color(to);
		register BITBOARD bb = sq_2_bb(from) ^ sq_2_bb(to);

		pieces[square[to]] ^= bb;
		pieces[color<<3] ^= bb;
		blockers ^= bb;

		square[from] = square[to];
		square[to] = 0;
	}
	int Position::rep_check(int check_times, int& win_trun, int& win_flags)
	{
		int ply = stack.size();
		win_trun = ColorNone;
		win_flags = 0;

		if (ply < check_times * 4)
			return Rep_None;

		U8 flag = Rep_None;
		bool me_check = true, opp_check = true;
		int rep_times = 0;

		for (int index = ply - 2; index >= 0; index -= 2)
		{
			if (stack[index].move == 0 
				|| stack[index].cap 
				|| stack[index + 1].move == 0 
				|| stack[index + 1].cap)
				break;
			if (me_check && !stack[index].check)
				me_check = false;
			if (opp_check && !stack[index+1].check)
				opp_check = false;
			if (stack[index].lock == key)
			{
				rep_times++;
				if (rep_times == check_times)
				{
					if (me_check && !opp_check)
					{
						win_trun = color_opp(turn);
						win_flags = Long_Check_Win;
						return Rep_Me_Ban;
					}
					if (!me_check && opp_check)
					{
						win_trun = turn;
						win_flags = Long_Check_Win;
						return Rep_Opp_Ban;
					}
					if(me_check && opp_check)
					{
						win_trun = ColorNone;
						win_flags = Long_Rep_Draw;
						return Rep_Draw;
					}
					int flag = check_move_catch();
					if ((flag & Flag_Me_Ban) && (flag & Flag_Opp_Ban))
					{
						win_trun = ColorNone;
						win_flags = Long_Rep_Draw;
						return Rep_Draw;
					}
					flag |= check_static_catch();
					if (flag == 0)
					{
						win_trun = ColorNone;
						win_flags = Long_Rep_Draw;
						return Rep_Draw;
					}
					if ((flag & Flag_Me_Ban) && (flag & Flag_Opp_Ban))
					{
						win_trun = ColorNone;
						win_flags = Long_Rep_Draw;
						return Rep_Draw;
					}
					if (flag & Flag_Me_Ban)
					{
						win_trun = color_opp(turn);
						win_flags = Long_Chase_Win;
						return Rep_Me_Ban;
					}
					if (flag & Flag_Opp_Ban)
					{
						win_trun = turn;
						win_flags = Long_Chase_Win;
						return Rep_Opp_Ban;
					}
					win_trun = ColorNone;
					win_flags = Long_Rep_Draw;
					return Rep_Draw;
				}
			}
		}
		return Rep_None;
	}
	int Position::rep_check(int check_times)
	{
		int ply = stack.size();
		if (ply < check_times * 4)
			return Rep_None;

		U8 flag = Rep_None;
		bool me_check = true, opp_check = true;
		int rep_times = 0;

		for (int index = ply - 2; index >= 0; index -= 2)
		{
			if (stack[index].move == 0 
				|| stack[index].cap 
				|| stack[index + 1].move == 0 
				|| stack[index + 1].cap)
				break;
			if (me_check && !stack[index].check)
				me_check = false;
			if (opp_check && !stack[index+1].check)
				opp_check = false;
			if (stack[index].lock == key)
			{
				rep_times++;
				if (rep_times == check_times)
				{
					if (me_check && !opp_check)
						return Rep_Me_Ban;
					if (!me_check && opp_check)
						return Rep_Opp_Ban;
					if(me_check && opp_check)
						return Rep_Draw;
					int flag = check_move_catch();
					if ((flag & Flag_Me_Ban) && (flag & Flag_Opp_Ban))
					{
						return Rep_Draw;
					}
					flag |= check_static_catch();
					if (flag == 0)
					{
						return Rep_Draw;
					}
					if ((flag & Flag_Me_Ban) && (flag & Flag_Opp_Ban))
					{
						return Rep_Draw;
					}
					if (flag & Flag_Me_Ban)
					{
						return Rep_Me_Ban;
					}
					if (flag & Flag_Opp_Ban)
					{
						return Rep_Opp_Ban;
					}
					return Rep_Draw;
				}
			}
		}
		return Rep_None;
	}

	int Position::check_move_catch()
	{
		int ply = stack.size();
		int ix, undo_ix = ply;

		bool me_ban = true, opp_ban = true;

		U16 me_last = stack[ply-2].move;
		U16 opp_last = stack[ply-1].move;
		U16 me_move, opp_move;

		//if (stack[ply-1].check)
		//	opp_ban = false;
		//if (stack[ply-2].check)
		//	me_ban = false;

		for (ix = ply - 4; ix >= 0; ix -=2)
		{
			me_move = stack[ix].move;
			opp_move = stack[ix+1].move;
			//有将军，不是长捉
			//if (stack[ix].check)
			//{
			//	me_ban = false;
			//}
			//if (stack[ix+1].check)
			//{
			//	opp_ban = false;
			//}
			//多子移动，不是长捉
			if (opp_ban && move_from(me_last) != move_to(me_move))
			{
				opp_ban = false;
			}
			if (me_ban && move_from(opp_last) != move_to(opp_move))
			{
				me_ban = false;
			}
			if (!me_ban && !opp_ban)
			{
				return Flag_Rep_None;
			}
			if (key == stack[ix].lock)
				break;
			me_last = me_move;
			opp_last = opp_move;
		}

		for (ix = ply - 2; ix >= 0; ix -=2)
		{
			me_move = stack[ix].move;
			opp_move = stack[ix+1].move;
			if (opp_ban && !move_attack_sq(opp_move, move_to(me_move)))
			{
				opp_ban = false;
			}
			rep_move_undo(opp_move);
			undo_ix --;

			if (me_ban && !move_attack_sq(me_move, move_from(opp_move)))
			{
				me_ban = false;
			}
			if (!me_ban && !opp_ban)
			{
				break;
			}

			if (key == stack[ix].lock)
				break;

			rep_move_undo(me_move);
			undo_ix --;
		}

		for (; undo_ix != ply; undo_ix ++)
		{
			rep_move_do(stack[undo_ix].move);
		}

		if (me_ban && !opp_ban)
		{
			return Flag_Me_Ban;
		}
		else if (!me_ban && opp_ban)
		{
			return Flag_Opp_Ban;
		}
		else if (me_ban && opp_ban)
		{
			return Flag_Me_Ban|Flag_Opp_Ban;
		}
		return Flag_Rep_None;
	}

	bool Position::move_attack_sq(int move, int sq)
	{
		//move 是移动后的move，sq是要攻击的sq

		S8 att_sq = move_to(move);
		S8 color = sq_piece_color(att_sq);//piece_color(square[att_sq]);
		S8 type = sq_piece_type(sq);//piece_type(square[sq]);
		S8 from = move_from(move);
		S8 to = move_to(move);

		if(type == Pawn && !sq_2_bb(sq)[color])
			return false;

		//被车攻击
		if (type != Rook || sq_is_pinned(sq))
		{
			BITBOARD bb = rook_attack_bb(sq, blockers) & piece_bb(color, Rook);
			while (bb)
			{
				int a_sq = bb.pop_1st_sq();
				if (a_sq == att_sq)
				{
					if (sq_equal_rank(from, to) 
						&& sq_equal_file(to, sq)
						&& !sq_rank_pinned(a_sq))
					{
						if (!sq_is_protected(sq, a_sq))
							return true;
					}
					else if ((sq_equal_file(from, to) 
						&& sq_equal_rank(to, sq)
						&& !sq_file_pinned(a_sq)))
					{
						if (!sq_is_protected(sq, a_sq))
							return true;
					}
				}
				else if (!sq_is_pinned(a_sq, blockers ^ sq_2_bb(sq)) && !sq_is_protected(sq, a_sq))
				{
					rep_move_undo(move);
					if (!(rook_attack_bb(a_sq, blockers) & sq_2_bb(sq)))
					{
						rep_move_do(move);
						return true;
					}
					if (sq_is_pinned(a_sq, blockers ^ sq_2_bb(sq)))
					{
						rep_move_do(move);
						return true;
					}
					if (sq_is_protected(sq, a_sq))
					{
						rep_move_do(move);
						return true;
					}
					rep_move_do(move);
				}
			}
		}
		//被炮攻击
		if (type != Cannon || sq_is_pinned(sq))
		{
			BITBOARD bb = cannon_attack_bb(sq, blockers) & piece_bb(color, Cannon);
			while (bb)
			{
				int a_sq = bb.pop_1st_sq();
				if (a_sq == att_sq)
				{
					if (sq_equal_rank(from, to) 
						&& sq_equal_file(to, sq)
						&& !sq_rank_pinned(a_sq))
					{
						if (type == Rook || !sq_is_protected(sq, a_sq))
							return true;
					}
					else if ((sq_equal_file(from, to) 
						&& sq_equal_rank(to, sq)
						&& !sq_file_pinned(a_sq)))
					{
						if (type == Rook || !sq_is_protected(sq, a_sq))
							return true;
					}
				}
				else
				{
					if (type == Cannon)
					{
						if (sq_equal_rank(a_sq, sq))
						{
							if (!(sq_file_pinned(a_sq) || sq_knight_pinned(a_sq)) && !sq_is_protected(sq, a_sq))
							{
								goto Check_Cannon_Attack;
							}
						}
						else
						{
							if (!(sq_rank_pinned(a_sq) || sq_knight_pinned(a_sq)) && !sq_is_protected(sq, a_sq))
							{
								goto Check_Cannon_Attack;
							}
						}
					}
					else if (!sq_is_pinned(a_sq) && (type == Rook || !sq_is_protected(sq, a_sq)))
					{
Check_Cannon_Attack:
						rep_move_undo(move);
						if (!(cannon_attack_bb(a_sq, blockers) & sq_2_bb(sq)))
						{
							rep_move_do(move);
							return true;
						}
						if (sq_is_pinned(a_sq))
						{
							rep_move_do(move);
							return true;
						}
						if (type != Rook && sq_is_protected(sq, a_sq))
						{
							rep_move_do(move);
							return true;
						}
						rep_move_do(move);
					}
				}
			}
		}

		//被马攻击
		BITBOARD bb = knight_attacked_bb(sq, blockers) & piece_bb(color, Knight);
		while (bb)
		{
			int a_sq = bb.pop_1st_sq();
			if (a_sq == att_sq)
			{
				if ((type != Knight || square[knight_legal_leg(sq, a_sq)] || sq_is_pinned(sq))
					&& !sq_is_pinned(a_sq))
				{
					if (type == Rook || !sq_is_protected(sq, a_sq))
						return true;
				}
			}
			else
			{
				if ((type != Knight || square[knight_legal_leg(sq, a_sq)] || sq_is_pinned(sq))
					&& !sq_is_pinned(a_sq) 
					&& (type == Rook || !sq_is_protected(sq, a_sq)))
				{
					rep_move_undo(move);
					if (square[knight_legal_leg(a_sq, sq)])
					{
						rep_move_do(move);
						return true;
					}
					if (sq_is_pinned(a_sq))
					{
						rep_move_do(move);
						return true;
					}
					if (type != Rook && sq_is_protected(sq, a_sq))
					{
						rep_move_do(move);
						return true;
					}
					rep_move_do(move);
				}
			}
		}

		//被象攻击

		if (is_bishop_pos(sq, color))
		{
			bb = bishop_attack_bb(sq, blockers) & piece_bb(color, Bishop);
			while (bb)
			{
				int a_sq = bb.pop_1st_sq();
				if (!sq_is_pinned(a_sq) 
					&& (type == Rook || !sq_is_protected(sq, a_sq)))
				{
					if (a_sq == att_sq)
						return true;

					rep_move_undo(move);
					if (square[(a_sq + sq)/2])
					{
						rep_move_do(move);
						return true;
					}
					if (sq_is_pinned(a_sq))
					{
						rep_move_do(move);
						return true;
					}
					if (type != Rook && sq_is_protected(sq, a_sq))
					{
						rep_move_do(move);
						return true;
					}
					rep_move_do(move);
				}
			}
		}

		//被士攻击

		if (is_advisor_pos(sq, color))
		{
			bb = advisor_attack_bb(sq) & piece_bb(color, Advisor);
			while (bb)
			{
				int a_sq = bb.pop_1st_sq();
				if (!sq_is_pinned(a_sq)
					&& (type == Rook || !sq_is_protected(sq, a_sq)))
				{
					if (a_sq == att_sq)
						return true;
					rep_move_undo(move);
					if (sq_is_pinned(a_sq))
					{
						rep_move_do(move);
						return true;
					}
					if (type != Rook && sq_is_protected(sq, a_sq))
					{
						rep_move_do(move);
						return true;
					}
					rep_move_do(move);
				}
			}
		}

		return false;
	}

	int Position::check_static_catch()
	{
		enum
		{
			Rank_None_In = 0, Rank_Me_In, Rank_Opp_In, Rank_All_In,
			File_None_In, File_Me_In, File_Opp_In, File_All_In,
		};
		int ply = stack.size();
		int ix, c_flag = 1;
		U16 me_move, opp_move;
		bool check_me_ban = true;
		bool check_opp_ban = true;
		int flag = 0;
		int me = turn, opp = color_opp(turn);
		BITBOARD moves_bb[2] = {BITBOARD(0, 0), BITBOARD(0, 0)};
		for (ix = ply - 2; ix >= 0; ix -= 2)
		{
			me_move = stack[ix].move;
			opp_move = stack[ix+1].move;
			//有将军，不是长捉
			if (stack[ix].check)
			{
				check_me_ban = false;
			}
			if (stack[ix+1].check)
			{
				check_opp_ban = false;
			}
			//if (stack[ix].check || stack[ix+1].check)
			//{
			//	return Flag_Rep_None;
			//}
			if (ix == ply - 2)
			{
				if (sq_equal_file(move_to(me_move), move_to(opp_move)))
				{
					flag |= (1 << File_All_In);
				}
				if (sq_equal_file(move_from(me_move), move_from(opp_move)))
				{
					flag |= (1 << File_None_In);
				}
				if (sq_equal_file(move_from(me_move), move_to(opp_move)))
				{
					flag |= (1 << File_Opp_In);
				}
				if (sq_equal_file(move_to(me_move), move_from(opp_move)))
				{
					flag |= (1 << File_Me_In);
				}
				if (sq_equal_rank(move_to(me_move), move_to(opp_move)))
				{
					flag |= 1 << (Rank_All_In);
				}
				if (sq_equal_rank(move_from(me_move), move_from(opp_move)))
				{
					flag |= (1 << Rank_None_In);
				}
				if (sq_equal_rank(move_from(me_move), move_to(opp_move)))
				{
					flag |= (1 << Rank_Opp_In);
				}
				if (sq_equal_rank(move_to(me_move), move_from(opp_move)))
				{
					flag |= (1 << Rank_Me_In);
				}
			}
			else
			{
				if (flag & (1<<File_All_In))
				{
					if (c_flag)
					{
						if (!sq_equal_file(move_to(me_move), move_to(opp_move)))
						{
							flag &= ~(1<<File_All_In);
						}
					}
					else
					{
						if (!sq_equal_file(move_from(me_move), move_from(opp_move)))
						{
							flag &= ~(1<<File_All_In);
						}
					}
				}
				if (flag & (1<<File_None_In))
				{
					if (!c_flag)
					{
						if (!sq_equal_file(move_to(me_move), move_to(opp_move)))
						{
							flag &= ~(1<<File_None_In);
						}
					}
					else
					{
						if (!sq_equal_file(move_from(me_move), move_from(opp_move)))
						{
							flag &= ~(1<<File_None_In);
						}
					}
				}
				if (flag & (1<<File_Opp_In))
				{
					if (c_flag)
					{
						if (!sq_equal_file(move_from(me_move), move_to(opp_move)))
						{
							flag &= ~(1<<File_Opp_In);
						}
					}
					else
					{
						if (!sq_equal_file(move_to(me_move), move_from(opp_move)))
						{
							flag &= ~(1<<File_Opp_In);
						}
					}
				}
				if (flag & (1<<File_Me_In))
				{
					if (!c_flag)
					{
						if (!sq_equal_file(move_from(me_move), move_to(opp_move)))
						{
							flag &= ~(1<<File_Me_In);
						}
					}
					else
					{
						if (!sq_equal_file(move_to(me_move), move_from(opp_move)))
						{
							flag &= ~(1<<File_Me_In);
						}
					}
				}
				if (flag & (1<<Rank_All_In))
				{
					if (c_flag)
					{
						if (!sq_equal_rank(move_to(me_move), move_to(opp_move)))
						{
							flag &= ~(1<<Rank_All_In);
						}
					}
					else
					{
						if (!sq_equal_rank(move_from(me_move), move_from(opp_move)))
						{
							flag &= ~(1<<Rank_All_In);
						}
					}
				}
				if (flag & (1<<Rank_None_In))
				{
					if (!c_flag)
					{
						if (!sq_equal_rank(move_to(me_move), move_to(opp_move)))
						{
							flag &= ~(1<<Rank_None_In);
						}
					}
					else
					{
						if (!sq_equal_rank(move_from(me_move), move_from(opp_move)))
						{
							flag &= ~(1<<Rank_None_In);
						}
					}
				}
				if (flag & (1<<Rank_Opp_In))
				{
					if (c_flag)
					{
						if (!sq_equal_rank(move_from(me_move), move_to(opp_move)))
						{
							flag &= ~(1<<Rank_Opp_In);
						}
					}
					else
					{
						if (!sq_equal_rank(move_to(me_move), move_from(opp_move)))
						{
							flag &= ~(1<<Rank_Opp_In);
						}
					}
				}
				if (flag & (1<<Rank_Me_In))
				{
					if (!c_flag)
					{
						if (!sq_equal_rank(move_from(me_move), move_to(opp_move)))
						{
							flag &= ~(1<<Rank_Me_In);
						}
					}
					else
					{
						if (!sq_equal_rank(move_to(me_move), move_from(opp_move)))
						{
							flag &= ~(1<<Rank_Me_In);
						}
					}
				}
			}
			if (flag == 0)
			{
				return Flag_Rep_None;
			}
			if (!check_me_ban && !check_opp_ban)
			{
				return Flag_Rep_None;
			}

			moves_bb[me] |= sq_2_bb(move_from(me_move))|sq_2_bb(move_to(me_move));
			moves_bb[opp] |= sq_2_bb(move_from(opp_move))|sq_2_bb(move_to(opp_move));

			if (key == stack[ix].lock)
				break;
			c_flag ^= 1;
		}
		S8 cap_sq;
		BITBOARD cap_bb = BITBOARD(0ULL, 0ULL);
		if (check_me_ban)
		{//检查己方长捉不动子
			rep_move_undo(stack[ply-1].move);
			gen_static_cap(cap_bb, me);
			rep_move_do(stack[ply-1].move);
			cap_bb &= ~(moves_bb[opp]);
			cap_bb[opp] &= ~pieces[piece_make(opp, Pawn)][opp];
			bool find = false;
			while(cap_bb)
			{
				cap_sq = cap_bb.pop_1st_sq();
				if (me_static_catch(cap_sq))
				{
					find = true;
					break;
				}
			}
			if (!find)
			{
				check_me_ban = false;
			}
		}
		if (check_opp_ban)
		{//检查对方长捉不动子
			cap_bb = BITBOARD(0ULL, 0ULL);
			gen_static_cap(cap_bb, opp);
			cap_bb &= ~(moves_bb[me]);
			cap_bb[me] &= ~pieces[piece_make(me, Pawn)][me];
			bool find = false;
			while(cap_bb)
			{
				cap_sq = cap_bb.pop_1st_sq();
				if (opp_static_catch(cap_sq))
				{
					find = true;
					break;
				}
			}
			if (!find)
			{
				check_opp_ban = false;
			}
		}
		if (check_me_ban && check_opp_ban)
		{
			return Flag_Me_Ban|Flag_Opp_Ban;
		}
		else if (check_me_ban)
		{
			return Flag_Me_Ban;
		}
		else if (check_opp_ban)
		{
			return Flag_Opp_Ban;
		}

		return Flag_Rep_None;
	}

	void Position::gen_static_cap(BITBOARD& bb, int color)
	{	
		S8 from, opp = color_opp(color);
		BITBOARD pieces_bb = pieces[piece_make(color, Advisor)];
		BITBOARD target = pieces[opp << 3];
		while(pieces_bb)
		{
			from = pieces_bb.pop_1st_sq();
			bb |= advisor_attack_bb(from) & target;
		}
		pieces_bb = pieces[piece_make(color, Bishop)];
		while(pieces_bb)
		{
			from = pieces_bb.pop_1st_sq();
			bb |= bishop_attack_bb(from, blockers) & target;
		}
		pieces_bb = pieces[piece_make(color, Knight)];
		while(pieces_bb)
		{
			from = pieces_bb.pop_1st_sq();
			bb |= knight_attack_bb(from, blockers) & target;
		}
		pieces_bb = pieces[piece_make(color, Cannon)];
		while(pieces_bb)
		{
			from = pieces_bb.pop_1st_sq();
			bb |= cannon_attack_bb(from, blockers) & target;
		}
		pieces_bb = pieces[piece_make(color, Rook)];
		while(pieces_bb)
		{
			from = pieces_bb.pop_1st_sq();
			bb |= rook_attack_bb(from, blockers) & target;
		}
		//pieces_bb = pieces[piece_make(color, Pawn)];
		//if (pieces_bb)
		//{
		//	if (color == White)
		//	{
		//		bb |= (pieces_bb << 9) & target;
		//	}
		//	else
		//	{
		//		bb |= (pieces_bb >> 9) & target;
		//	}
		//	if (pieces_bb[opp])
		//	{
		//		bb[opp] |= (pieces_bb[opp] << 1) & ~file_mask(File_A)[opp] & target[opp];
		//		bb[opp] |= (pieces_bb[opp] >> 1) & ~file_mask(File_I)[opp] & target[opp];
		//	}
		//}
	}

	bool Position::me_static_catch(int sq)
	{
		int ply = stack.size();
		int undo_ix = ply;
		bool ban = true;
		U16 me_move, opp_move;
		int me = turn;

		for (int ix = ply - 2; ix >= 0; ix -=2)
		{
			me_move = stack[ix].move;
			opp_move = stack[ix+1].move;

			rep_move_undo(opp_move);
			undo_ix --;
			if (sq_piece_color(sq) != color_opp(me)
				|| !move_attack_sq(me_move, sq))
			{
				ban = false;
				break;
			}
			if (key == stack[ix].lock)
				break;

			rep_move_undo(me_move);
			undo_ix --;
		}

		for (; undo_ix != ply; undo_ix ++)
		{
			rep_move_do(stack[undo_ix].move);
		}
		return ban;
	}
	bool Position::opp_static_catch(int sq)
	{
		int ply = stack.size();
		int undo_ix = ply;
		bool ban = true;
		U16 me_move, opp_move;
		int me = turn;

		for (int ix = ply - 2; ix >= 0; ix -=2)
		{
			me_move = stack[ix].move;
			opp_move = stack[ix+1].move;
			if (sq_piece_color(sq) != me 
				|| !move_attack_sq(opp_move, sq))
			{
				ban = false;
				break;
			}
			if (key == stack[ix].lock)
				break;
			rep_move_undo(opp_move);
			undo_ix --;
			rep_move_undo(me_move);
			undo_ix --;
		}

		for (; undo_ix != ply; undo_ix ++)
		{
			rep_move_do(stack[undo_ix].move);
		}
		return ban;
	}

	bool Position::sq_is_protected(int sq, int att_sq)
	{
		int me = sq_piece_color(sq);
		int opp = color_opp(me);
		BITBOARD block = blockers ^ sq_2_bb(att_sq);
		S8 k_pos = pieces[piece_make(me, King)].peek_1st_sq();

		if (sq_equal_rank(att_sq, k_pos))
		{
			if (!sq_equal_rank(sq, att_sq))
			{
				if (rook_rank_attack_bb(k_pos, block) & piece_bb(opp, Rook))
				{//要抽将吃, 必须应将
					return false;
				}
				BITBOARD bb = cannon_rank_attack_bb(k_pos, block) & piece_bb(opp, Cannon);
				if (bb)
				{
					S8 c_pos = bb.peek_1st_sq();
					S8 pin = (sq_between_bb(c_pos, k_pos) & block).peek_1st_sq();
					if (!sq_is_pinned(pin, block))
					{
						if (square[pin] == piece_make(me, Knight))
						{
							if (knight_attack_bb(pin, block) & sq_2_bb(sq))
							{
								return true;
							}
						}
						else if (square[pin] == piece_make(me, Advisor))
						{
							if (advisor_attack_bb(pin) & sq_2_bb(sq))
							{
								return true;
							}
						}
						else if (square[pin] == piece_make(me, Rook))
						{
							if (rook_attack_bb(pin, block) & sq_2_bb(sq))
							{
								return true;
							}
						}
						else if (square[pin] == piece_make(me, Cannon))
						{
							if (cannon_attack_bb(pin, block) & sq_2_bb(sq))
							{
								return true;
							}
						}
					}
					return false;
				}
			}
		}
		else if (sq_equal_file(att_sq, k_pos))
		{
			if (!sq_equal_file(sq, att_sq))
			{
				if (rook_file_attack_bb(k_pos, block) & piece_bb(opp, Rook))
				{//要抽将吃, 必须应将
					return false;
				}
				BITBOARD bb = cannon_file_attack_bb(k_pos, block) & piece_bb(opp, Cannon);
				if (bb)
				{
					S8 c_pos = bb.peek_1st_sq();
					S8 pin = (sq_between_bb(c_pos, k_pos) & block).peek_1st_sq();
					if (!sq_is_pinned(pin, block))
					{
						if (square[pin] == piece_make(me, Knight))
						{
							if (knight_attack_bb(pin, block) & sq_2_bb(sq))
							{
								return true;
							}
						}
						else if (square[pin] == piece_make(me, Advisor))
						{
							if (advisor_attack_bb(pin) & sq_2_bb(sq))
							{
								return true;
							}
						}
						else if (square[pin] == piece_make(me, Rook))
						{
							if (rook_attack_bb(pin, block) & sq_2_bb(sq))
							{
								return true;
							}
						}
						else if (square[pin] == piece_make(me, Cannon))
						{
							if (cannon_attack_bb(pin, block) & sq_2_bb(sq))
							{
								return true;
							}
						}
					}
					return false;
				}
			}
		}
		else if (is_leg_pos(att_sq, k_pos))
		{
			if (knight_attacked_bb(k_pos, block) & piece_bb(opp, Knight))
			{
				return false;
			}
		}

		BITBOARD piece = pawn_attacked_bb(sq, me) & piece_bb(me, Pawn);
		while (piece)
		{
			if (!sq_is_pinned(piece.pop_1st_sq(), block))
				return true;
		}
		if (slide_att_no_mask(sq) & piece_bb(me, Rook))
		{
			piece = rook_attack_bb(sq, block) & piece_bb(me, Rook);
			while (piece)
			{
				if (!sq_is_pinned(piece.pop_1st_sq(), block))
					return true;
			}
		}
		if (slide_att_no_mask(sq) & piece_bb(me, Cannon))
		{
			piece = cannon_attack_bb(sq, block) & piece_bb(me, Cannon);
			while (piece)
			{
				if (!sq_is_pinned(piece.pop_1st_sq(), block))
					return true;
			}
		}
		if (is_advisor_pos(sq, me))
		{
			piece = advisor_attack_bb(sq) & piece_bb(me, Advisor);
			while (piece)
			{
				if (!sq_is_pinned(piece.pop_1st_sq(), block))
					return true;
			}
		}
		if (is_bishop_pos(sq, me))
		{
			piece = bishop_attack_bb(sq, block) & piece_bb(me, Bishop);
			while (piece)
			{
				if (!sq_is_pinned(piece.pop_1st_sq(), block))
					return true;
			}
		}
		if (knight_att_no_mask(sq) & piece_bb(me, Knight))
		{
			piece = knight_attacked_bb(sq, block) & piece_bb(me, Knight);
			while (piece)
			{
				if (!sq_is_pinned(piece.pop_1st_sq(), block))
					return true;
			}
		}
		if (is_king_pos(sq, me))
		{
			if (sq_king_protected(sq, att_sq))
				return true;
		}
		return false;

	}

	bool Position::sq_king_protected(int sq, int att_sq)
	{
		int me = sq_piece_color(sq);

		if (!is_king_pos(sq, me))
			return false;
		if (!(king_attack_bb(sq)[me] & piece_bb(me, King)[me]))
			return false;

		me = color_opp(me);

		BITBOARD blocks = blockers^sq_2_bb(att_sq);

		S8 k_pos = pieces[piece_make(me, King)].peek_1st_sq();
		if (sq_equal_file(sq, k_pos) && !(file_between_bb(sq, k_pos) & blocks))
			return false;

		BITBOARD piece = pawn_attacked_bb(sq, me) & piece_bb(me, Pawn) & blocks;
		while (piece)
		{
			if (!sq_is_pinned(piece.pop_1st_sq(), blocks))
				return false;
		}
		if (knight_att_no_mask(sq) & piece_bb(me, Knight))
		{
			piece = knight_attacked_bb(sq,blocks) & piece_bb(me, Knight) & blocks;
			while (piece)
			{
				if (!sq_is_pinned(piece.pop_1st_sq(), blocks))
					return false;
			}
		}

		if (slide_att_no_mask(sq) & piece_bb(me, Rook))
		{
			piece = rook_attack_bb(sq,blocks) & piece_bb(me, Rook) & blocks;
			while (piece)
			{
				if (!sq_is_pinned(piece.pop_1st_sq(), blocks))
					return false;
			}
		}
		if (slide_att_no_mask(sq) & piece_bb(me, Cannon))
		{
			piece = cannon_attack_bb(sq, blocks) & piece_bb(me, Cannon) & blocks;
			while (piece)
			{
				if (!sq_is_pinned(piece.pop_1st_sq(), blocks))
					return false;
			}
		}
		return true;
	}

	bool Position::sq_rank_pinned(int sq, const BITBOARD& block)
	{

		S8 me = sq_piece_color(sq);
		S8 opp = color_opp(me);
		S8 k_pos = pieces[piece_make(me, King)].peek_1st_sq();
		S8 att_sq;

		if (!sq_equal_rank(k_pos, sq))
		{
			return false;
		}
		BITBOARD piecebb = sq_rank_mask(k_pos) & piece_bb(opp, Rook) & block;
		while(piecebb)
		{
			att_sq = piecebb.pop_1st_sq();
			if ((rank_between_bb(att_sq, k_pos) & block).only_1_bit_set() && Mid<S8>(sq, k_pos, att_sq))
			{
				return true;
			}
		}
		piecebb = sq_rank_mask(k_pos) & piece_bb(opp, Cannon) & block;
		while(piecebb)
		{
			att_sq = piecebb.pop_1st_sq();
			if ((rank_between_bb(att_sq, k_pos) & block).only_2_bit_set() && Mid<S8>(sq, k_pos, att_sq))
			{
				return true;
			}
		}
		return false;
	}

	bool Position::sq_file_pinned(int sq, const BITBOARD& block)
	{
		S8 me = sq_piece_color(sq);
		S8 opp = color_opp(me);
		S8 k_pos = pieces[piece_make(me, King)].peek_1st_sq();
		S8 att_sq;

		if (!sq_equal_file(k_pos, sq))
			return false;

		S8 pin_nb = (file_between_bb(sq, k_pos) & block).count_bits();
		if (pin_nb > 1)
			return false;

		if (pin_nb == 0)
		{
			BITBOARD piecebb = sq_file_mask(k_pos) & (piece_bb(opp, Rook)|piece_bb(opp, King)) & block;
			while(piecebb)
			{
				att_sq = piecebb.pop_1st_sq();
				if ((file_between_bb(att_sq, k_pos) & block).only_1_bit_set() && Mid<S8>(sq, k_pos, att_sq))
				{
					return true;
				}
			}
		}
		BITBOARD piecebb = sq_file_mask(k_pos) & piece_bb(opp, Cannon) & block;
		while(piecebb)
		{
			att_sq = piecebb.pop_1st_sq();
			if ((file_between_bb(att_sq, k_pos) & block).only_2_bit_set() && Mid<S8>(sq, k_pos, att_sq))
			{
				return true;
			}
		}
		return false;
	}
	bool Position::sq_knight_pinned(int sq, const BITBOARD& block)
	{
		S8 me = sq_piece_color(sq);//piece_color(square[sq]);
		S8 opp = color_opp(me);
		S8 k_pos = pieces[piece_make(me, King)].peek_1st_sq();

		if (is_leg_pos(sq, k_pos))
		{
			U64 bits = knight_att_no_mask(k_pos)[me] & piece_bb(opp, Knight)[me] & block[me];
			while(bits)
			{
				S8 pin_sq = pop_1st_sq(bits, me);
				if (sq == knight_legal_leg(pin_sq, k_pos))
				{
					return true;
				}
			}
		}
		return false;
	}
	bool Position::sq_is_pinned(int sq, const BITBOARD& block)
	{
		if (sq_knight_pinned(sq, block) 
			|| sq_rank_pinned(sq, block) 
			|| sq_file_pinned(sq, block))
			return true;
		return false;
	}

	bool Position::is_chase(int move)
	{
		S8 to = move_to(move), target, opp = color_opp(turn);
		rep_move_do(move);
		BITBOARD pieces_bb = pieces[piece_make(opp, Advisor)];
		while(pieces_bb)
		{
			target = pieces_bb.pop_1st_sq();
			if(to != target && move_attack_sq(move, target))
				return true;
		}
		pieces_bb = pieces[piece_make(opp, Bishop)];
		while(pieces_bb)
		{
			target = pieces_bb.pop_1st_sq();
			if(to != target && move_attack_sq(move, target))
				return true;
		}
		pieces_bb = pieces[piece_make(opp, Knight)];
		while(pieces_bb)
		{
			target = pieces_bb.pop_1st_sq();
			if(to != target && move_attack_sq(move, target))
				return true;
		}
		pieces_bb = pieces[piece_make(opp, Cannon)];
		while(pieces_bb)
		{
			target = pieces_bb.pop_1st_sq();
			if(to != target && move_attack_sq(move, target))
				return true;
		}
		pieces_bb = pieces[piece_make(opp, Rook)];
		while(pieces_bb)
		{
			target = pieces_bb.pop_1st_sq();
			if(to != target && move_attack_sq(move, target))
				return true;
		}
		pieces_bb = pieces[piece_make(opp, Pawn)];
		while(pieces_bb)
		{
			target = pieces_bb.pop_1st_sq();
			if(to != target && move_attack_sq(move, target))
				return true;
		}
		return false;
	}

	BITBOARD File_Block_Mask[9];
	BITBOARD Rank_Block_Mask[10];
	BITBOARD Bishop_Block_Mask[14];
	BITBOARD Knight_Block_Mask[90];
	BITBOARD Knight_Attd_Mask[90];
	BITBOARD Bishop_Att_BB[14][16];
	BITBOARD Knight_Att_BB[90][16];
	BITBOARD Knight_Attd_BB[90][16];
	BITBOARD Rook_Rank_Att_Table[90][128];
	BITBOARD Rook_File_Att_Table[90][256];
	BITBOARD Cannon_Rank_Att_Table[90][128];
	BITBOARD Cannon_File_Att_Table[90][256];

	BITBOARD King_Att[18];
	BITBOARD Advisor_Att[10];
	BITBOARD Pawn_Att[90][2];
	BITBOARD Attd_Pawn[90][2];

	BITBOARD Bishop_Att_No_Mask[14];
	BITBOARD Knight_Att_No_Mask[90];

	BITBOARD Rank_Mask[10];
	BITBOARD File_Mask[9];
	BITBOARD Up_Down_Mask[10][2];
	BITBOARD Left_Right_Mask[9][2];
	BITBOARD Rank_Between_Mask[9][16];
	BITBOARD File_Between_Mask[10][16];

	const UINT64 ZobristPlayer = 0xA0CE2AF90C452F58;
	const UINT64 ZobristTable[3584] =
	{
		0x7130B4BD8F138026,  0x451A5F875056AE15,  0x9023211DB6E216DD,  0x8176B9AB5178BE31,  0x9CA65525FE49D1F0,  
		0x64BFA2303868852B,  0xB91360D20127098E,  0x36150C526E1DD2F5,  0xD8BBFB8FCD6F735D,  0xA3B35E61D7DA5068,  
		0x46982BFDF96E1DCD,  0x012367021814AD81,  0x4089DA4C1B9C5662,  0x42BBDB342F88A0D4,  0xC827E492D9CEB711,  
		0x4E18FABBC55DBE46,  0xFB7A0B8AC6284121,  0xF179FC42457A105A,  0xF5A6CFA529C8D035,  0xED7626E641383689,  
		0x3B8A9E8457E65E67,  0x674957C0D8CE647F,  0x7C4CE37B578F1A9B,  0x07F9D32932E1493B,  0xAC776EB186FCC474,  
		0x3FE8BF61B3D17258,  0x04B55A2FB8F42D93,  0xC0DD14998777FF0F,  0x6E4E1E15DB62B600,  0x846AE109AE2C37B7,  
		0x7093E9E05DF029FB,  0xD3982B39A0FDB1C7,  0xBDE6DB97B7F5A17C,  0xC0EED455913ADDA6,  0x46947371FECE7628,  
		0x81AEF4C1CC7A02CF,  0xC5C82E68E036A296,  0x7FA039EF30781817,  0xAAE0E8DEEFF3F606,  0x1D0521C1E13B610E,  
		0x69F10F80F4A40A00,  0x197FE1B1681516DA,  0xCACFBC19E54CE37C,  0x233B0A0A4B37F1F9,  0xC90B6A25FFB22F73,  
		0x7574FC9E93A8FBCF,  0x2A3A777D6F54AB13,  0x96920D6C2292F1EA,  0x25862C838D6591EF,  0xF6242FA4AF008A5E,  
		0xC8FCB0CE3BC170D8,  0x18D91DC3523B5FB1,  0xE118A157278E0A46,  0xEF116C3273168425,  0x5F19D7CB03CA217F,  
		0x44E11F566FAF8769,  0xAD2C7BA5F0A013D9,  0x7188039CA11F66F2,  0xB60BF14EF215B3CA,  0xEAF97C8185E0C08E,  
		0xEAAF8D87B72DEFA2,  0x69CADA520DBDFFF2,  0xEDBA60006A42FE2A,  0x5CF499B4F530734D,  0xEBD032FF7C032574,  
		0xED0CEFE2DE548828,  0x63982B947C1044A4,  0x7E34A6BFAA97391B,  0x021DE9E384DEA780,  0xF0B240D20A7A3E21,  
		0x9A6A479E6C2962F8,  0x443FBA6FCFE3AC8A,  0x0B94FFD875CA1C18,  0xCB58573E538730E6,  0xD936CAF0DC8EB6FD,  
		0xDC5C557CB71F3C59,  0x79102F57CB1791B8,  0xB825EF53C44BB033,  0xAFDA588F7EA0AF51,  0xC2B5F9C4E30B95CB,  
		0x80A454CAEDF92144,  0xDCE464932ADF15E8,  0x37C78B2ED8C9A22F,  0x6F89F2DC6ECB7A3B,  0xC66174B2BDBAC28C,  
		0x0B5FECE55E935CBE,  0x7F6D244689C750A1,  0xF6DB5CE7369C13EE,  0x1DFE7BE1079E5717,  0x3E8FD681C406383B,  
		0x26C4AFB21394B9D8,  0xCF2FC6C843BF9E29,  0xEFEAF2C2C752AF1E,  0xAC072DA2A15421E9,  0x9B88BCE097F522D8,  
		0xEBD45C9DDD79F483,  0x944A0CB6EA118CD7,  0x2A2D9F08F4688FC3,  0x5B935E97509CF65A,  0xDF28D78E81335D7D,  
		0xCE54AC786E5569F5,  0x73BF3C535D72C7F1,  0xFBE4F2426CFBE0EB,  0x2175DFE5E3BCA451,  0x4AA446981A35836D,  
		0x391597228F7485B6,  0xDAD29FD49FA7CD5A,  0x90C83E823DAED609,  0xCAE55B04A2616F7C,  0x97B7D80D98F6E3A8,  
		0xBBDC533A45662552,  0x66558A90C4EE35D1,  0xA1710EA33BB6C1E7,  0x28B3A66776D9BF1F,  0xD3AC2058AFD6FA44,  
		0x75E9909B554C3C8F,  0x87519DF971800282,  0x7E3D65D3834888F0,  0x32BC129FBDBBFA89,  0x93D99FE52A4A37B1,  
		0x5F2A71E5FA4BF9F5,  0x0118DEABF2CAB75C,  0xE524B92B0AE556C5,  0xF6017B176BF8DB47,  0xBF8CEF69A56598BB,  
		0xB6491634B1744D44,  0x1613D072E1BB7B8F,  0x1C48393EF0FDDB53,  0x47312B801AF3FC6C,  0x1D89CBA1D23AAAA0,  
		0xBD6ADA8CF8674350,  0x152C541877B2E05D,  0x85997C0948AE573D,  0x610FDEECE2659A30,  0x460566FD239E8469,  
		0x3AD870AE78696B4B,  0xAA9C6EC2753A3DC6,  0xF71096789320D072,  0x5327FB17490C1F9A,  0xDD3FBF4552CAFC71,  
		0x47579F4DD4221F05,  0x8D93C8864B2CCFD4,  0xD395BBF07B5A72A0,  0xD5C21F99785D11E4,  0xF309D54DD472EAA0,  
		0x510B1D7B92B4662C,  0x18CFCADDC9DCD31E,  0xA8D9266A96235115,  0x7E56238CC3F22970,  0x86334FF6EB3AB765,  
		0x20FB95886DDB75BF,  0xC24CD15A9F5DEF9C,  0xE76DB13580FB8C3B,  0x57BC1FB405AF897C,  0x59F0CA8C1F7B659A,  
		0xF06F06193B70AF52,  0x09A2A61D94F9B4C2,  0x20393C4228A1C5AC,  0xFBF0B3A97C496FD6,  0x6AE149E1B8E081A3,  
		0x6AE2A31D317E3CFC,  0x20DABC87F88EE2E6,  0xF283C6864964A78F,  0xD9602E474779A623,  0xE1993F7829FE40A2,  
		0x4D6D0818B4572D85,  0x02010D007B4765F9,  0x171880531B8D5860,  0x957A1458A42BECEC,  0x6E226759D7CFA040,  
		0xE03C160B0D306AC5,  0x3703D6F03C56E0F8,  0x75B40F5598EEDA9B,  0x0FA29F77B672C261,  0x8EDB5023922F80C2,  
		0x95CC2DA8DF7D1DEC,  0x070B750DA000B638,  0xE1E38F29C032BF35,  0x6DD75E5089CE4AC5,  0x7DB988B3D3B35634,  
		0x445C2CCFA024FA9D,  0xDE4A5149426CAAC5,  0xD4A088B2E2591CCB,  0xF9260F515C7BEC95,  0x54051E52DE03C1B2,  
		0xA592BA34D6F9A7C4,  0x086E39A6F2CA055D,  0x47F9F977810A45B0,  0x2CB93A8143A3EF7A,  0x6E00F5059360E2C8,  
		0x9E344875D6536B35,  0x44B0BDD03046755C,  0x8C3B984FDA84BB4E,  0xE2591594EA2916BE,  0x8EC32296B3886320,  
		0x7D657D057BEB8736,  0x3A80FEA71258DB6A,  0x9A200450904B8E99,  0xBB8CB47E59282224,  0x2D67375E4CCD7677,  
		0xABBA445D0E5E56A6,  0x3BA418E098C6584A,  0xEA93C301BA87AFE3,  0x1BD589AC92372907,  0xCBC7DF3D935B4087,  
		0x904D689B984C1CF6,  0x48025646359B3D40,  0x4BC51E890E7181D0,  0x5592CB241034E377,  0x6BB63DCC0319D264,  
		0x63E7C742ACA0C341,  0x826BF0E102605E56,  0x50D0C2231B2C1D51,  0xDE0B7CC516E3B9B6,  0xAAA010D0DD6A4E35,  
		0x9FD64CD35A469385,  0x28AD6EBF5DB67222,  0x7235ABC802ED5F5A,  0x8E61954D80469917,  0x6EA2CBDC5DAABDCA,  
		0xC5DD713688F7192C,  0xF04902B8E0359041,  0x9073D9CA988D5D33,  0x574779548452F866,  0x1E98C0DA4CDB082C,  
		0xB4BDF7A2EBCD784E,  0x008DE7CF00C67A09,  0x8B5D1C3C726D5000,  0x26FD82782BD1C0DD,  0xE4F1AD0E95465E12,  
		0xD0DD76A8DC765970,  0xF5755359BDCD047A,  0x545A1CD1E52664BD,  0xB16E9726D3472FB8,  0xF5342D4D398633FC,  
		0x01F5E0A47E506E06,  0xBDDFA4284FFB5311,  0xCE7D3CAC503D553C,  0x9BDF9DC98B5099A1,  0x4D7DB1040B5E997A,  
		0x5D3D05D360E35524,  0x337BA8BC212C7BE1,  0x86A62B460947E29A,  0x3D513D5CA88EEFE1,  0x29A0CCE9F41C1CD5,  
		0x197FD26418A34EE2,  0x326F3B949B426C85,  0x3E4E91EA83647D53,  0xCFA3E8FD16681952,  0x59BDEF07E7CD5168,  
		0x341025521D64C7D1,  0xCEEAF8F1C434AB08,  0x409C4FDF6688E61F,  0x643AB4959FA3CDBD,  0x58C41B99A5AB395A,  
		0xF0B655B8D42A00A9,  0xABD7437EC956585B,  0x3F42808B843F0DC0,  0xE0C928421512B453,  0x85E82CD69A61C0E7,  
		0x0C3C34CD0A7DEE44,  0xA82B08CCC44BD09A,  0xE2A835B21E653066,  0x077406CF9230F54F,  0x1CD68CB8E3D724F9,  
		0x85DAEB464697B1B0,  0x7DA2593F4CA08018,  0x8825EA023C853D5D,  0xEEC8F4378562F880,  0x059AC163DFC9F4DA,  
		0xF9C81F2073038B6F,  0x314738E40E6974D0,  0x8327245D17DF9208,  0x02AD6C54622EEBD2,  0x3C3768ED10B692D8,  
		0x2D4A31901EA2053E,  0x433957859408E871,  0xF1307F2059AF68F0,  0xFE02DFAFD2155E43,  0x5CFFDBA1747776E9,  
		0xC9A5848E286D570B,  0xBCC49B8DE5DEF315,  0xBC3F0A86F9987C91,  0xFBD32161F98D94D2,  0x27031D1D87EBEE9C,  
		0x137EA6D6042F2EE6,  0x7FBA0AD49A60F731,  0xBF8E614730F0380C,  0xA45457FEDAC904A5,  0xED9F8B297C43B13C,  
		0xA2D9CF016E619E07,  0xE82794BDF52D8E54,  0x8DE9C087EC7044E6,  0x5A950B05805F2ED9,  0x6421FCCBF228CF8E,  
		0xDC1439499F9BEFDF,  0x692C94144FC54921,  0x13C21B59B3FB3D5C,  0x0BE3042A904A613F,  0x05A6B8EF1ABA9873,  
		0xAFD0468D5425FB1C,  0xED8F697BEA759978,  0xE390DBBC06690C31,  0x7DF25EF2C1B3D7BB,  0x72EE3703C4FE44EB,  
		0x274421EE4FE5A662,  0x1540B7C94DE20203,  0xB9B835E58EFF0CD5,  0x30874D584E06536D,  0x12263CF38E0B9A89,  
		0x51CFFCD4B2168DF8,  0x74DB1C017C23812D,  0x9DEF49F43E19EF14,  0x106285F49F650D8A,  0x7432FEBD1E556661,  
		0x70DC8AD69498F68F,  0xF19E609342B42EEA,  0xB43E22B4625CDB64,  0x606AED6D8D629241,  0x12E0FF48DDC8FC78,  
		0xAEEC871C960889D2,  0x200E4F561E9D90E9,  0xC4A4C01F24A7072C,  0x45BC5EDC5634E0AE,  0x0E33718AF9BD0A0D,  
		0x8F78D4320E85D575,  0xDAFFA02864F5E370,  0xEC86C7522DB34F12,  0xD3D923E5F844A6FD,  0xFA7D0A7A1EB505E4,  
		0x027B6460BAF76879,  0x2A38E595F8D474B2,  0xA0C2F34BC6D8892F,  0xDAC414AEB5C574BE,  0xFD8EFE0F19341970,  
		0x8AD040FA4163BA22,  0xAEAF1F094212BC94,  0x33B8FFE4761403B6,  0x9CE6C86CE5BE2223,  0x727C17C73609E90D,  
		0x62F7DAC41F27950F,  0xF5EA32D84BBC8A53,  0xF4CBBBB5657BEA2A,  0x0F517A14DB0E5108,  0xCA3E12B18BC14936,  
		0xFE30DFD5B8A4BDEE,  0xE3B114C76F0F7848,  0xC2081FF9FE39BFA8,  0x377B82E296760752,  0x99221E6A70AF8EDD,  
		0xA86B92570F640A10,  0x9A3E88088FD8DFD5,  0x18FD2A9A59E788A9,  0x9B4761EBF8122EEF,  0xCE8F38AD29D683C9,  
		0x0AC79B1BA2DB545F,  0x0DC614B7C478E6FE,  0xA69F31CD15C23518,  0xCF769CF9BDFF1C95,  0xA27CE272F619A1CF,  
		0xEDD97E2FF6A93857,  0x8DE4D8C20C0A926E,  0x1E7089339D1BEACE,  0x4E1DCD2008B63B80,  0x4FEDD394920F34FE,  
		0x5E218FB6693C4C55,  0x8E97598B791934B2,  0x0FB211C4DB9C47EF,  0x8F06AEAFB2F1EBCB,  0xAF04F990627F2FF7,  
		0x38CEC469D73EA940,  0xDFF6C99EE2257050,  0x6A77CD2AEE82C8A2,  0xF28554C80AC672F9,  0x406AEE0390776562,  
		0xA653B1E543DACF62,  0xC2CF09484FB7F138,  0xE44857CB17E0F569,  0xACFE5877A93AE94D,  0x6BD6B075B1555386,  
		0x5E274DADACC63C1C,  0x51537D31C7AB98FB,  0xA7D0F1826B19E227,  0xB5B888D02E42A80B,  0x86632D398F3B45F3,  
		0xA88454C497646176,  0x237E0EBD89E4EBE8,  0xBBEA1E661284F9CD,  0x1BCE97F0C8B76903,  0x4C517E505F19D26A,  
		0x9C3B79717E79AF83,  0xB827B135E474AAFF,  0x0EAA55F3EE469AF4,  0x6652634B833F3E24,  0xA7473AF5A12B8146,  
		0xF21671B7CE444A46,  0x0A1DE189D45D74D4,  0xE510F44C4E5EF9E4,  0x2FFEEAA2ADCC6380,  0x54E8791C10816108,  
		0xA3122938856EE959,  0xF4A0DF4C24EA2B4E,  0x791DAE527B579162,  0x730962D6F3B66D04,  0xB57432EE8D29ED6C,  
		0xBA80A3BD252CA320,  0xC0A2AE71513DF629,  0xB453147D5B2C9923,  0x225F093A925116E3,  0x6542396F255E7924,  
		0x2CDFCE9FA44BB47A,  0xC34970F43ACF098F,  0xE9AEEB95D937F58F,  0x687B4F4521D5DD65,  0x01300BE22536A20E,  
		0xE5DFC3E9922C4F02,  0x717B6ABCE8D6AA77,  0xE57DB6BA0D58D2A6,  0x60D651626AC55B90,  0xD64502A5EE95D561,  
		0xB5FA2A17EC8C0164,  0xC9582135958FC611,  0xEE8344C1E19954C4,  0x7837CF255667618B,  0xC448CF344C71909F,  
		0x109EC4308D96B82D,  0x3F04BAF84B9A88EA,  0xBF639A875F62F26C,  0x7AA0384D965722F7,  0x197B692B50B16B14,  
		0x6D9AF6C73900AF62,  0x1344B3CA12371956,  0x806E82E6B15E7006,  0xB485FE720F18C9E3,  0xE87881B804FC9892,  
		0xB514FFD89D201D92,  0xB0DA1B717631E6B5,  0xBCE52DB116F37D72,  0xF3E7E0B0C0031705,  0xC44047E6F7A8FF33,  
		0x6A2B3F09E5E20DFF,  0xD8376D5B4B60E246,  0xEA9A751191B618D6,  0x85E15B1EF98B2D2B,  0x5C9F283D995EBFF4,  
		0x46C291DE5BB153C4,  0x399E0B67FC70554D,  0xBBC5509EC6B802A2,  0x5B232FE5E38EC2FE,  0xC46C93A6ECB300A8,  
		0x0E7D08AD8C6C32C9,  0xEF7946C452725F83,  0x5875BB0EC00C0569,  0xC2FCAEF70627BCB7,  0x1603571CDC91C8DE,  
		0x7DDE8CCB1B957059,  0x9331DEF3087DFF1E,  0x0E23128AF65503B2,  0x422DA38E3ADD22C0,  0xF7C673B863F5F95A,  
		0x1B41B4020A90FDAF,  0x51C9A20D3DB6A18B,  0xA5C02C6A966BA5E1,  0xA417B39904E238C1,  0x9338C0FB38935E99,  
		0x532CE15BF4CFB3DC,  0xEC04532D412240D6,  0x27FA420EA2C7B462,  0x181677150EAE7BC7,  0x553BED9EBE1E7896,  
		0x5B2FD1742EFBC680,  0x418CA72B61F20679,  0xF1F0683866BE4E53,  0xD8C0F92A762C1DF7,  0x67F3229FBCEE1969,  
		0x099F4DA05E6DFDC4,  0x3805504714CF8B92,  0x80D22F3733C207BF,  0xB8AFC305A9790B6D,  0xA8F9FB39C90AA4D2,  
		0xBAB73A768636C050,  0xCC0A34644A373DA4,  0x8ED715B148CD959B,  0x55A80EAC2B7D849B,  0x8DEE3BB83D4AAE58,  
		0xBB07E90EDFE6F703,  0xC4F051B49E974C5B,  0x24CCAFB135A33651,  0x06626B3223BEF039,  0xB4B82274CABEF7DA,  
		0x57C76808A76733D2,  0x557FEE74D5E09877,  0x544F71C8CD9E2745,  0x20E51FAB44F3B2F3,  0x8943A2FF3BC05883,  
		0x91327F52FEA5BB31,  0x5E0DF9B866E337DB,  0x598F2F63ABD2E563,  0x0365F043D6BC5038,  0x461A8FE29B10D7DC,  
		0x3516573BE5B357E7,  0x3B8DEB7F1AB21F34,  0x69EF366CEA5A8721,  0xD828E25554ADE7DE,  0x67EBB3483B39F3A8,  
		0xD6F7DF759404ED5F,  0x212F071B4B677D3B,  0xDD046C22AC5AAEC0,  0xFB6E1153DD1E2CB2,  0x97D35E894A8C98FE,  
		0x087A6EAD9F06D7F4,  0x3F8EE504C8484B7B,  0x0E149930E1A2F734,  0x678F3ECCFCA9AFC0,  0x7EC9927F53DD6C0E,  
		0xCF722347391CA511,  0xBF909DF5085B997C,  0x2FC2DDF6F3D0499E,  0x5FFF5EBAD0DD23C2,  0x293372619835465D,  
		0x9F57AAF3298911B9,  0xAEB705081A173FCD,  0xE156D4BA23ACE526,  0x3B50E0E6C107FD2C,  0xCC966FC46612A601,  
		0x16364FC077ECC8F4,  0x6B7A9AF718B2DCD1,  0x54E5F2C147A6508E,  0x5A0AD4605220A294,  0x45256CE34BE5AE9F,  
		0xC8C29F8DC6BED0BE,  0x9256D4BEAE5EA267,  0xA046AE47B4550A60,  0xD4641C4CCEB20FF5,  0xA61B2E4D3854DF6F,  
		0xD4865E6EBC7E904A,  0x20DA3FBB53A7BDC5,  0x6774FFD7552EE5A7,  0xAD132B56FC964F54,  0x6711BF4F78356788,  
		0x24E69A066DDE5B9B,  0xF96EE40FA2943B2A,  0xB592D351C9CB526C,  0xD2152449A594C085,  0xD9984BD710A76073,  
		0x36B4D5BA5CCE5126,  0x35B99229FB8F622A,  0x9BF8927ECCB2954C,  0x750A14A82F53481B,  0x8BF66928F4E81D2F,  
		0x6E657161D698179B,  0xD7C3A46668EEE763,  0xB60E8638AF30B565,  0x5AF8A85EF5A2DAB3,  0x7AE0EEF45C21A3C6,  
		0x247AA638834FC8E1,  0xD963AD160483642A,  0x9DA66D060A24A134,  0xE239BDC416F74C54,  0x8A033EAE9A075CBF,  
		0x16CC89355A20E98B,  0x97E8BB34EECCB3B9,  0xB0BF009D6C1D9072,  0x880FC10CD715A26C,  0xD0946F9A9DA78677,  
		0x90C74201DE237D80,  0x9828A0C7591DD9F4,  0xE395B5817809A0A5,  0xC7F8BE13AA5D1073,  0xE35176E9ABED6FF6,  
		0x6CE4712469EE5EBC,  0x574834D0A8E2C384,  0x40FBBA002CA43496,  0x3FCDF103605E35E9,  0x2F0DFEE4107C165B,  
		0x239DA452341381D8,  0xA81F632B381798D4,  0xADB419068568EFFD,  0x558BC0C2A7D867F7,  0x52DC6F3DC9A41DB5,  
		0x448773B36A459F7E,  0x56EBD31F3832EE5E,  0x69D785DB8CFC746D,  0xCDAE6A497F74144D,  0xE904160454095107,  
		0x5CD6579330A59BB5,  0x8AEA9509973A20B8,  0xA4BE1E940C9B10FE,  0x1E8429E083833009,  0x2F9E9F3691208D5D,  
		0x75D61DD81A41C493,  0x8BDB28E4E1ED77AD,  0x0A704178E8B6FB88,  0xC85218B2B04BECD8,  0x3A808C043BCCA15B,  
		0xBB26AA37219ADA54,  0x4B6CAF966EBF2377,  0x1E40CB982F082E7D,  0xCB0CBE8CC6E98537,  0x62C8169757F2EDD7,  
		0xBF044FD343AE7379,  0x08265E464C84C974,  0xEC67F355C6E3BE7B,  0x05A8BF507746521C,  0xCABAA1E3A903B7EB,  
		0xC199639F0A6D64E6,  0xE680C85653CD434B,  0x87B9656878E9415C,  0xEB06C0EEC6C86120,  0x4545E58C133D2E6E,  
		0x6AA5835BDAAAB17D,  0x843EB16DE5557AB4,  0x92B5CFF85B46E8EC,  0x246BD153F4B3CDD3,  0xCE8AA159CB3D0AC2,  
		0x78A49D94A5697C01,  0xBD3504584166FE64,  0x2C289ABEA06329FA,  0xA278FE4BB569D106,  0x385C0F22DECFDEEB,  
		0xFE44C745A7A73BE5,  0x5107BB0BC463F317,  0x9124D6A54045E715,  0xE63EEC2DFD7C6D40,  0xB192B76D71B6EB54,  
		0x615A80B62E26A624,  0xEFABD35404C0D980,  0x87FC8AA76C504084,  0x94BC639D5EAE9CA6,  0xC6D9950989667D95,  
		0x9C3C215075ECF3C0,  0xE00E45BA9EDD00C7,  0x8E3A077C2DED92A0,  0x180C6C876D39034A,  0xB1E265BD20EAC59A,  
		0x02B45678EE4416B8,  0x3BB043529C90C9E1,  0x21FA671C4945B7C6,  0x80008F9B2E71FCC3,  0x82799CD6AB3A64F8,  
		0x1A2B97E4758C9E1E,  0x8AA35524650F829F,  0xCBEBD8076FFC36C5,  0x98C055F927295CB1,  0xE2C23F594E6A51AD,  
		0x64BF6640836F6037,  0x2B33D20EE28F2F21,  0x66D74CD256720168,  0xAE1EAC36AA9DFB46,  0x2548D6FBDC1F80AA,  
		0x3D111B0CB124EDB7,  0x5415A20F4DD03010,  0x0972A7671F829E07,  0x934AA23FBD72CC08,  0xC17ACC9DE0B7D964,  
		0x257F7853FCD7BD60,  0x9F51165472F56FB7,  0xE27B0B998821FFC5,  0x2466011FEFECD2EB,  0x837221C7E79BBF67,  
		0x2EF0A2110E8B114C,  0x311A87501740596F,  0x9BAC4BC3545ABC17,  0xD9D9BBF5416D165F,  0xA456C8904170BDB0,  
		0xB99CD546C64F029F,  0x3E19552C5F768F1F,  0xD76C36F3EAC008BF,  0x0BE9B0EF2ADFB2C0,  0xE099D3B5276BB233,  
		0x62221DA3B51EEA4A,  0xA86ED4E6B4290695,  0xC3EACBCD8739D897,  0xEF853EA99BA436BB,  0x1AC355D75DC033D5,  
		0x21825EC968846814,  0xC65998B8B9C4EB0B,  0x94AFC15F5F69DE31,  0xF1080F2C5E25BA12,  0x06F79B8C40333B69,  
		0x2DBE19A10D01A975,  0xF90FCE647D1FEEEE,  0xC0B7D49E9EDF73D3,  0x752BE6837F80F5D4,  0xCF5ACD66C3A9D0B6,  
		0x6450A38C37D125DA,  0x86AD0D334D4C4507,  0xC66DB22062239BF5,  0x3D485A707445E378,  0xCFACAEB72000EDE4,  
		0x975438F880456BA3,  0x3AE8D40255DFB564,  0x7AF66254096884B2,  0xD00C9865E49B44B3,  0x5BD1E997CA6778C4,  
		0xDF1B075126479F85,  0xB697C791A08B6870,  0x57F0891F1209809C,  0xFC51277583FCFA13,  0xF551026B5B9E139B,  
		0xC1F3DE5B21841ED2,  0x79A08EA3D1636BD4,  0x15FA4462B687376A,  0x6EAA4CE26EDBF41B,  0x7D21516CC8A2BD52,  
		0xEA24B5F5D9BF68E7,  0xC3114CDDF3EA28B6,  0x9825B2C894CAB544,  0xBDA8F3F7FD69AA4C,  0x3D85FF2AA5A61469,  
		0xB3BC58E48335081D,  0xF836424CC24FF4EE,  0xC48FC99A2FE70EB9,  0x0CD680125EA617ED,  0xEDF22D536D0D2462,  
		0x215FD0A92BC595A0,  0xADCA3D6756B0B23B,  0x5E829AAB51032234,  0x53108ED7D1B5D786,  0x465AB35DE184F0E6,  
		0x1B955103077C4560,  0x91685C689987B8A8,  0xA19B577112BDC5B0,  0x04412AC0CB81F4E2,  0x183A9CC8045A5E20,  
		0x2338EB44DF7AD60A,  0x31A20F803A46C84F,  0x4F436AD8A60F4122,  0x00B9CA0277902AA9,  0x72A0B5A98CAD8A67,  
		0x824F5B6AA9EFA97F,  0xD6643F8981C316B2,  0xE2DBA038B8121E5C,  0x55B7CA2255B09051,  0x271E7EC9BB5F13AA,  
		0x3ABD19142874AF72,  0x912C0E83909C1D18,  0x153ACBE2C4238B4D,  0x4B3AC62C9C6ED971,  0x7ECB7DE0E960D0AA,  
		0x275D29F8E36D68B8,  0xD50AA91BD5296388,  0xE985B86950F1F9CB,  0x9A448E9DAE6BACDD,  0x01914A2324A154D9,  
		0xEA76281FDDF872CF,  0xFFC5207D2422046C,  0xE6F259AA1C8368DC,  0x210DDC8A452B04DE,  0xC8C97057488C76BF,  
		0xBB7A70FDF3A9C269,  0x13178AD6611ED81C,  0xA0D5384E886CB836,  0xB4A70407DA7B7C3A,  0xD6E0521ADE4B471A,  
		0x9DDC946DAEE4C44A,  0x84AA4ACEDE74E8DD,  0xA6A86FE717E2B81A,  0xD491DB2E002D4D40,  0xBA43FE950B69541D,  
		0x34F9E6647CD4C022,  0xADC60580747E012A,  0x405888DD46C40469,  0x1D2679F87012656D,  0xF22E2C29901DA5A9,  
		0x0A08856A64D75F53,  0x03A350CA865BB292,  0xB2B822C5A0186E82,  0xB1E859D43FF96CB1,  0xE0006E4B01966414,  
		0x342483D5DB41CE0C,  0x4014B0FC75A9BAAF,  0xA0A3749E1FE3E398,  0xED8735AD8EF74035,  0x0B191FECC08F73A2,  
		0x7D536308882B961F,  0x4A3F7A3E4684C99D,  0x00479FA69A58CABD,  0x9BB5E26DA6935CF9,  0x3CA49FB0ED9CBCF0,  
		0xE3F290F1E5AD6EE6,  0x668E5A4A3FF16D22,  0x273F9C16B2DBBB38,  0xCAF51C537915217F,  0x6A24FF949CEB82C3,  
		0xCAE1F1EF4A9E28C0,  0x95483787F3E099E9,  0x4E9BC472786CDE04,  0x3CB266CAE0CBD432,  0xE2E40346BFD7298E,  
		0xAE961353B24EAE20,  0xA08D4F9112F8E560,  0xCC152439B0AC08A3,  0x51F9C03DC9C01A0C,  0xD131E0A029EE35DB,  
		0x1498C2618B6F4733,  0x71F878D0353B0CFF,  0x183BACB6115B2C81,  0x2C1DE757D4304BAA,  0x4D2C684106EA9B32,  
		0x57B2DB20418EC4E4,  0xDE2EA8083ADB0D64,  0x0933C0EB4E575291,  0x7F222204DB0A67B8,  0xA528AEC950E03C34,  
		0xE5C4485956133319,  0xA3AB6AA0C541DE2B,  0x1213B717C533979C,  0x3A9709EE3AE5DECE,  0xE123FCC1350CBEDE,  
		0x21C9207730D33B11,  0x81B745E74CF65344,  0x3FC581BFF8CAFA9C,  0x87BA1B3DBAB5E305,  0x20350194C8FF7B7B,  
		0xDCC4609F738CD0F7,  0xFB218717B4CC8FCE,  0x4A11CF7893B50264,  0x85780F4A7E732C25,  0xA5DFF339327E7078,  
		0xAB400C1DFE73B366,  0x5CF50F5D2B5C7D0B,  0x1C23C7A2E0DE9575,  0x9310BFD66B61B5D1,  0x25489C041D6B07F6,  
		0x0C54EA7B8EB75E36,  0xAA206C84FCE12CDC,  0x603C2E6F4ABEF76E,  0xD2C79DCE1CFE10A6,  0xFE7A593F8FC15F83,  
		0x23A378635B901A7A,  0x712B1CD00010536C,  0xD168AB2A8A30E27A,  0x77FE60F41AB5F566,  0x304D717F6DA2F706,  
		0xA7950BE44CE5C030,  0xBF19F45CBE7877D3,  0x690B31994F8258DA,  0x20F1DCB78C3CA5EE,  0xF9B677558D274C3C,  
		0x35155A33F117AA34,  0x0463F288D157C25A,  0x4C8440EB5956EFBC,  0x7DEBB4777A74E13F,  0xCC53D716A9181647,  
		0xC8B5A2EB9E5DCA11,  0x32AFBBEA29C8C0BA,  0xC7D665844CA91E6C,  0xADE8001949E46E20,  0xACAFA2FDE184A14E,  
		0x1A94D9F442F5AFD6,  0x3B89FE2C397D1E0E,  0x79C03729D4807DC2,  0x76640B24D075993B,  0xCC3030CD961231C8,  
		0xF33F066EF548BA59,  0xE650F745D76565E1,  0x4E7045D3C7A72ACF,  0x2AE92F5D43121C73,  0x8C11D8CBF6E4A584,  
		0x93A853C5A6FB50E7,  0x376D5140F68CF402,  0x7FC8A2DECD305E8A,  0xB644C8BD20AC6916,  0xE466F3B458B2263A,  
		0x2A28DDE90DEADE41,  0x49D682A38B190F75,  0x3D8E6E8510A0A07E,  0x57242239DABE7FBD,  0xDF24CEE742476222,  
		0x132143633CB53B74,  0x85ECC54BB9AA82E7,  0xD2B73D12226EE596,  0xF5E0F118147D9C5A,  0x60EBE31C90919002,  
		0x6182D88AC7FB104A,  0xFFEA5A178B291430,  0x926A4E0E726DA7EC,  0xED84AE8842EC4C7D,  0x1BFC4DCBF28E75C6,  
		0x23154CDBE005D081,  0x61B4AFD921D071A4,  0xC2437117A05C1B04,  0x7FFAA7B53BCD7D2D,  0xF01FA550EA050E8D,  
		0xDD3A7A97C727F8C5,  0x202FF086161C35A2,  0x63098F64C3519BE0,  0x8B6B9080FCEE6E2C,  0x8E64F0E0BAD3B0FF,  
		0xFDD124FBD9F47BAA,  0xFC9A8120EAC4F4DE,  0x4227B4589CC5520A,  0x4A3DC7F3BE4179A5,  0x98A2AEBC93C45B62,  
		0xA48AE951EFE36219,  0xEC8A8F8035E814ED,  0x95E6A0C1033D5E1D,  0xB0B41A6A52ADB3E5,  0xBDAF0ED0FD9F5909,  
		0xF474564301C7213B,  0xCC5A0ABDD7671398,  0x0CEED4D537DE1343,  0x58E79783D661BE84,  0x82F9B58A523EEEBD,  
		0x25F38588E5C2E805,  0x0E855F5CE0F874EB,  0xE53D644BD96DFDCD,  0x4F5614E51D91AA9E,  0x7A40E65FE0689640,  
		0x920905E1FC1DE44C,  0x3986F140455FF6EC,  0xC1C660A105050DB8,  0x0C99D664045B3390,  0x14A8E7460F9BA7B8,  
		0xDC13773E39D2983E,  0xD4CBD4F4F016A510,  0xEC00CEB009762A51,  0xBC18717E5F315789,  0x44E0FBC21A20374E,  
		0x77553337365A10A0,  0x46CBE73BF081F5EF,  0x879D223238FB8588,  0x2ED76C189342FCE4,  0x6A52FA2931F17C56,  
		0xAA94DD9201639414,  0x08C66CEE5400588B,  0xA48E50D8A6D8F85C,  0x6C308A4FB4A6D75A,  0x10F12855EB725F23,  
		0x0A4AF7E54A54C05E,  0xAD1836B1BD44AE3A,  0x2CB78F5A79A68D95,  0x9173FC9659E5C5E5,  0x538F503FD8EC25E5,  
		0xE557D988A0F0B5FC,  0xDBD9B79F0DDBC770,  0x197539F52E6A1483,  0xAF5546FDEEFDBB80,  0x7A5CCEE4A4B0BB30,  
		0x4DE3F2A108E673DA,  0xF222629A33D342B5,  0xD4119768B71151AF,  0xC1473CABD74275C7,  0x37987FAB50B6A08E,  
		0x1557F3F97AEAFB39,  0x846A681263A753F8,  0xF135393105F16DA9,  0x7CB14577C1C96493,  0x29C08567B365D088,  
		0xF65E476829855207,  0x2BB66190B0589D8B,  0x334AFBEAB5FDE105,  0x06BE417FB2F4D2C6,  0x579274D2719CB915,  
		0xA849635CEF43C8FE,  0x76B6C0D944131C14,  0xD89B3F56BC77FAF8,  0x4D4917666C97A18B,  0x4F5FC69B30B119C9,  
		0xDC35C0E4B1C0BA4A,  0x45815081B94D1F7A,  0xB6803326D20254E8,  0x896A95118AF5D879,  0x541AAD61B2715A13,  
		0xEBBBA8EB36C6E5B0,  0xAEB7FDD53512EFE0,  0xBE6EABE388FBD437,  0x39D468522C9A1578,  0x59BE957699B964FC,  
		0xC7E10451F916C4C7,  0x9AA1B47EF1A7CDDB,  0x7D613F6DDFBA6E2B,  0x8877E676DA316EF2,  0x39F3618E4F7A622F,  
		0x248E51D7EC59FA3F,  0xD8A85F3C24EEA7CA,  0x086822F2794230C8,  0xAEACD80D8973E1CE,  0x3940BEF8448D6FD6,  
		0x5B3D573BE430545D,  0x2A0269B842F92211,  0x67F6CEF5674BE3A2,  0x8AFACBDAAE9E937E,  0x5F09D81D782C1722,  
		0x51D4F5458E70F4AC,  0xE775C3AE6F4AD959,  0xF6F195978FAA5893,  0xD060650ADABEE18B,  0x60F9E77A8E0179F8,  
		0xD5BF7116B63F05EB,  0x0E90A6E36A906846,  0xCBF78101940B2E85,  0x924FF21EA192314A,  0x5FB8FD40E3A9D58B,  
		0xC8C77DDAB415842E,  0x1D4AD13AC639FFFC,  0x24F9E1363D0E73A1,  0x589D8EC71B86F1BE,  0x47DD041EF026381D,  
		0x3FE6BDA50FCE229C,  0x54A8BC27D4F3F099,  0xE72D7AAA97B735CA,  0xB84D56449A372F35,  0x4E1A886CDEA27BDB,  
		0xB82A42B0A307709F,  0x2C83ABC55B0DE752,  0xE52D278EFAC9C03C,  0x2F930595AD80E635,  0x56C37AA975251064,  
		0xDB1514CA87F45740,  0x26971EFDAC0A852D,  0x025CCBA2C6605FB7,  0x5CCF739C18356995,  0x8C56CDD844B9CEE4,  
		0xD69F5AA9EF969210,  0x50CEA651833A0EC0,  0xA028F5281139DCC9,  0xBB8C6E98777AED5C,  0x9150F672D75B9F0D,  
		0x3EDCE4602787E104,  0xCCDA3D38368470BC,  0x343EA5F0C3AB5934,  0x6C31C2FBA39A39BC,  0xA15289684C59C8D2,  
		0x9A9603061B04FABB,  0x4ADA004513406A4F,  0x09CFA9F69808D1C0,  0xD974DCC839155C98,  0xE37803F15DBF8461,  
		0x0DF53D47957B3006,  0x05D3CCC4AA14B496,  0x478D9E9AA2CADCA5,  0xAC8CAF224F5CA281,  0x86BF665A7D53778F,  
		0x6E209A5FCA434CA7,  0x3EDD3BC0AC31632F,  0xE8A2B500FFD83164,  0x1717067F697EB6A2,  0x7574C99AAAB6B7A5,  
		0xBD7589F9E0414296,  0x95E2CF786658AA35,  0xABC854DAC01CFE58,  0x341954AAC4CD0815,  0x027CA50F016C55E8,  
		0x3EB0A80D351E05BA,  0xD17372C328025A54,  0xB314C3087FE44629,  0xA556D608E77AC7A6,  0x8E5330C10B93E046,  
		0x429B0E62699FC026,  0x06685E98FB3B03D2,  0xF838FD7A860212C6,  0x71E4F4C99884D2EC,  0xED5BAAE7218EF2EC,  
		0xE2D4212D9CF31813,  0x08A3C9DAD580C1FA,  0xB60CF612DE69B5F6,  0x17489F45CEB8FF3C,  0xA3A4374FE833D599,  
		0x2845F2EBB917B130,  0x99FEDC96ABE04096,  0x1DF3EC88E624B33F,  0x9D04255EBC6AD089,  0xF0C603345AE4D55B,  
		0xA8438C807A38B9DD,  0x2A9C1CB2F65EB720,  0x3F5C4BFAFFAF079A,  0xECF5E88A98FC4E71,  0xBDCA0821C4292EEA,  
		0xA782CB2E848129A5,  0x783638C556440464,  0x09ECF4AB3D0347B6,  0x3FBF52B946A06264,  0xAD6B67D06CE2651C,  
		0x0528606A6938C6F8,  0xCA8A26E21869EA39,  0x58AF39057DB7692A,  0xD7C175677159D07A,  0x854C2F005E2B90B1,  
		0xDFDEE7C57F42E59D,  0x6D6CD4AA8FC3284A,  0x15E714DE3F2E60BF,  0xBDB8CBB3422CE24B,  0x9101CFFCFBC2531A,  
		0x02430F68B886A831,  0x682B7DEB969DAE9D,  0xFD88DCC349BEC133,  0x54C8831B3453F6C4,  0x70ED3B1EA684F122,  
		0x5EE99654DE07C45A,  0x35E628D027F9981F,  0x77EAF786DE54A30C,  0xB7D723A05C7364EB,  0x2A4EA8BCCAB707F3,  
		0x529F0276DECCC6DF,  0xC20D1474776FC285,  0xF3262F5B88CBC9D3,  0x41486C06694D6583,  0x87C1DB3F8A5FB573,  
		0xB4321EED5F974BE9,  0xA80953CDA57D7AD8,  0x4E1BFC44EFCA1DE5,  0x40C24AD8C996FE5F,  0x83165EEACD9BA45C,  
		0xB2D1D2C611BFF118,  0x3723963D63385D96,  0xF5A587A5C5B2043C,  0xD7F2157E386B33F1,  0x2053C57EF8051A8D,  
		0x123616777AF47FDD,  0xD2B6BD9BBB110690,  0x5A242D096EE6306C,  0xC30ECA7EB20B31FE,  0xB9350CDDCB9A222F,  
		0x4743806C451489E0,  0xAC445C88B85C6247,  0xEC9DBB4FBD0E0C32,  0x3E42E5F0638D6BCE,  0x27E0A606CF212704,  
		0x2F1DA6EB37A6E7F9,  0x5BF03F0330198E68,  0x6621FA8463212DB1,  0x38B686616CBE95BB,  0x5510EF7C6AE03B73,  
		0xD8CA5E88067D4205,  0xA73A67157A66BEA9,  0xDC556D97BADE0680,  0x285FCC5C81C07DEB,  0x0D0DAFCEB059B98D,  
		0x63C97BA69693B7C2,  0xDB91FD578C381F9D,  0x2EDE500AA4954DDE,  0x14499CBDFB593AD6,  0x6DB72534690D74E8,  
		0x72EA2A9F02D2317F,  0xCD8E52FBA5DEAB52,  0xA2137AF8C57B6279,  0xFA9561B3D2127DCD,  0x99F174C7989C764A,  
		0xA6A176457885AE59,  0x27A7B9734C0BB489,  0xF6465FA4D905BB07,  0x214522E4393870AD,  0xB463885664B813DC,  
		0x295218D708B04E88,  0x8ACA5A337C579B7E,  0x1B89446E2ED73DF8,  0xAB8DA4BF95646497,  0x9C1DD3B82E9F2E98,  
		0xEBB752E703100E06,  0x0DECC242443E6F6D,  0xF780180CF84DBA60,  0xEC4EAB9AB9ECC3EF,  0xEBD6B9E619F97349,  
		0x1CB65CED9DE73ED5,  0x4AE4E0AD8ACE67AE,  0x65213FC823013C8E,  0x1B6C45C466676BE9,  0x9058254AAC43B254,  
		0xA73B15EF0D298557,  0x6A52E2F2E8274433,  0x15A42BE5D8A526E4,  0xC78DAC6D791D037F,  0xC5C7EE04368B2A99,  
		0xABF3B4AD3F40A88D,  0xABA9DA6F27FD9438,  0x82FED7E2321A5DAC,  0x34724C1EE39F535D,  0x74FD13ABA19696AF,  
		0x43E644C582649FC8,  0x6EED5739325C478A,  0xC1054F9959CCB8B9,  0xDD33ADDD43CE65C8,  0x0BE6E3A219C1D87F,  
		0xE768A7E3ED454BF2,  0x755A0D2ED90D9FB4,  0x1ECF834DEBF6A312,  0x136BB9B0D8DAA7B5,  0xBB8B44627C57B5FD,  
		0x0EEAAB44566D624F,  0xA86C40DC37BDD309,  0xDF1D7DC229DBFCCF,  0xEC3E4BBFB23A7457,  0x344CCA42591D36C2,  
		0x9BC1A7BF04C21BDF,  0x396CFB8C5883112B,  0x7B067E5F34D777D5,  0xB313F1FD14337904,  0xE1A4A6DA4D03CD2D,  
		0xF0190BFC79EC283B,  0x05589D19C0A0A143,  0xB89BED2DF7007A8E,  0x83CF1AE2E97778EC,  0xB4DD761623F66FF1,  
		0xB0F607AA96F29280,  0x003BABFC4E0C9C62,  0xC4F0BA54CCB711A3,  0x7FC8B966DE50655C,  0xF5D1476C3992F6CD,  
		0x695F36972EB23747,  0xA787C23867D6C1E3,  0xC9BB3304D723E191,  0xE9F9E364F5549663,  0xA00AA8DC87541658,  
		0xCC00E8B64B51F0F1,  0xDD8D3E21055D32CD,  0xBC122AA51DDBC945,  0x0A4480148E3A87BE,  0x06A06A7D3621A8C4,  
		0xF65E21280296E5DA,  0xA0CA51F33C7A9D55,  0x54E873B8A90C47B9,  0x75B237F624EDD12F,  0xA98A487346A2A3B0,  
		0x7FE5F1C8D438C3AB,  0x7260E24D86E8C9E6,  0xE882574A935D7460,  0xF2C99F890EB4475D,  0xB547E19FBCF21922,  
		0x35CAEB4C4722A4BE,  0xDF9DC0388188808A,  0xC0F609EE9A2A9027,  0xB2879D8F7799DE34,  0xECFF7F1AE697A35B,  
		0xE6DAE6B82F8EBAE0,  0xD9FA6C8906FA93F1,  0x358C13397D9C7209,  0x84069E150DAE4180,  0x01A9D96F6141D7C3,  
		0x5468E88DB7B8D5DC,  0x40B26306ED6024CC,  0xD471CFA638EB15D8,  0xBA2C88F91BFE6C3C,  0xED38D9034D43252F,  
		0x98F892B4D5EB753E,  0xDB1E6A70D6306E7E,  0x6B987CF8B099ACAD,  0xC82E13D39E0B287A,  0xF6B2BE3183A04D8F,  
		0xE6E03689509223BF,  0x785DABFEC3762CC4,  0x8166FF6B750038F6,  0x5D4783CA90239369,  0x1A93C2BE64D4E51D,  
		0xB4989B3FE4B394B2,  0xBE931DEC82197231,  0x2674D8A7975E1F4E,  0x251975F0B8848495,  0x65499B172A827F9B,  
		0x96519EEE067F19E8,  0x659BC299539C6F25,  0x39B6D57DCDB08423,  0xCCD5C55D5F94F74E,  0x0C37F8CDE655C435,  
		0x3F95E43542D2A811,  0xAB6289B84D44E984,  0x154FB28CB7B0C137,  0x08003A912A2657EC,  0xCB90D843D6FDBB82,  
		0x9575D97042031C3B,  0xD107CAB69C63F092,  0xC65F5755D9EB5740,  0xE973497C53A6C38F,  0xF447458DFE1ED1D7,  
		0x31E46747C3D1F1E2,  0x1A047C537BB690AA,  0xE24A03929A82EA84,  0xD82DBDB7C5754C75,  0x40030A9E23AA03A3,  
		0x7B3E526BA0001C0C,  0x3F3B2A93893671B7,  0xB569F70FB6696F81,  0xF020226D3237503C,  0x6CCADC4C858B4812,  
		0x6B83F592AA372BA1,  0xBB7A1DF78B5B6EC3,  0xB24879F307929D39,  0xA44C921FFEF45BDA,  0x6DFC19A65ACE7D2B,  
		0xD6532BEDAEC41B97,  0x895050FE50F543B7,  0x9CEA0BCD63D8D0D5,  0x0EA32236283A3A46,  0x4404BA737BF1147C,  
		0x23955CC2282AE620,  0x3293FACBB7A168EE,  0xE4B4C39585EF71C0,  0x81423C07E65ADAD1,  0x7586477AC1221719,  
		0xAC73647FCFEDC4EA,  0xE1C504F3DEFBFC53,  0xD7563430219F92DC,  0xBE73B3E4BFA165BA,  0x55013E31249B5F10,  
		0x66650E96E489E2FF,  0x4DFCB7900420720D,  0x9828597E671582FE,  0xF642FB8693730E0A,  0x74CF59689B7F709B,  
		0x1BA56D143E371F82,  0xC9C9DEA0B687747B,  0x58B3309B8170740C,  0xFE1CACD4CB4202A7,  0xC69ED92920130ACC,  
		0xFE810561A2A98854,  0xFB4ED89DA3ABFE34,  0x3E8047F50F98ED65,  0xB1A7EC0648337CF1,  0x186AB04A000FFE6C,  
		0xE34BC1FF59E75833,  0xC50C630F2FAD0729,  0xF66B7C06347CE7B3,  0xC04FB3DACF7A9ADC,  0x69F7F13964B4F82B,  
		0x0B7EC65FFC2F2EED,  0xD861850ECFF8B711,  0x8AA5B9E13E4F95A8,  0xD73EFB19E14226D8,  0x4A95233A5693E22A,  
		0x029B960BB72DA90B,  0xA257AB9C8D269BAF,  0x5F5967A794C427F3,  0x1F69EC73A37A35E4,  0xCAF4E5764D17EFAB,  
		0x21D687B32E7E54E2,  0x62233E91717DE6D4,  0x4E587B200A2DC704,  0x6D2EF5EF5AC3A142,  0x6AF158F6CF8D23B7,  
		0xF2996E2F5F6BCB57,  0xA7E99CA0834575EB,  0x2872A3E753893AF0,  0x85F5D2FA9D3491DD,  0xD501AE14F28E9B02,  
		0xBC4856FF58678145,  0xC1BBC557F7E4B967,  0xF8994976F7111E32,  0xDA380E3058D58A66,  0x51BDE09C572CD41C,  
		0xA5AA948CB0F08BF2,  0x4D28677EE2ADDFF3,  0xE6A5F37D29A5E2C4,  0xCAB7382B591F1B2F,  0x1C3EEEFC5E80E5B2,  
		0xBA809B8630D5B333,  0xAB6033436106DFF1,  0x0FCFDA00A2DF7582,  0x78FA613231DAB129,  0x454FBD346706E28F,  
		0x6FEDEDEAF06C2A7C,  0xFA681FAD3C63D436,  0x99EB68C5CF1229FA,  0x2B1CE20B9F018221,  0x83373A5A2F1E120F,  
		0xC44066EC845CDD9C,  0xE01EC5650EFFE0EF,  0xBF9965DC6E7EEFB3,  0x821A82E8D445EC14,  0x089EACE220B6E786,  
		0xA3FB01ED5BDDAE3D,  0x1CB87C0B48FD2C35,  0x9A2CC4DF8494BA99,  0x0B79BAA4CE38DCDE,  0x70026E9382805605,  
		0x0E100EA5ADB68272,  0x971E938A1D90FF77,  0xE32ED01D314B227A,  0x147DF51DF231631B,  0x8801C04653B12F00,  
		0x714B6FD7487CDFAF,  0x493DAA3229D74F30,  0x0E8EE02C4527FC0C,  0xD32A95CB65F1FD77,  0x4BEFB58AFEE47B15,  
		0xEE8D11458C47CB26,  0xB52ADE928BA5365B,  0xCC9C1CDA01CB0EE3,  0xC987CEFE0AC39C31,  0x67B74D0281AEAA6D,  
		0xA67C5BBFB3ABAC0C,  0x035C54358954BD7C,  0x74D61070AC52A463,  0x6DDE8A787103D6CE,  0xC82EF638075BD765,  
		0x63AEEAE23BF85195,  0xB5116BE9AF6FD846,  0x8889B1897387DCE4,  0x9520ED1E9BEB78F1,  0xD8A53B1A6726FBD3,  
		0x3BBC3EA95AA7F058,  0x2D0896A73647F06C,  0xBAFDEDCC2B410BC6,  0x24769615E128C8A1,  0x52A2092901E211D9,  
		0x07E0A5DF0ABD7BDA,  0x9241BA7AF22F8C09,  0xB821659BE01100E1,  0x087F12ACE6A913F1,  0x2CC154384890CF2E,  
		0x332212FD0D4C93B0,  0x1AD3986A5ECEABE5,  0x42CDE963F0153516,  0x71809460427BC207,  0x41E21887AE6C9187,  
		0x299A3E69625EA69E,  0x733E601AE456A4AE,  0x909F5BA7F04B5CF6,  0x450C158AA4BD9E77,  0x7FDB09B1511E0414,  
		0x4753FA7B2DDE84F2,  0xB7D6144F90015E15,  0xD0140299117F3504,  0x4114B95F6E3CAB17,  0x60AC28DCD62A4913,  
		0x0F296A2620172CD8,  0x04E31164C35E4F15,  0xE466C33A2B4DE535,  0x5C6D64A8002C13A0,  0xDD066E73F4DF1124,  
		0x86C836C4526EADF8,  0x1A62C12721FA52ED,  0x085D0E450C57F928,  0x13E74038CB0641A0,  0xE154BCCDB6C3D0A6,  
		0x1DA4D77027D4F922,  0xBC1E3D9E3047CB1D,  0x4DFF95B959371D49,  0xFD9D55FF33AC5C45,  0x16B318D74E485BD3,  
		0xA518062F2C0CCEFA,  0xD370F45AC2DBA449,  0xB8655A77918B7AED,  0x23A7BD7C80AD5A0A,  0xEB849FA8A71305A5,  
		0x8F8793D12DFE840A,  0xF3B0E840805374AD,  0xDC2051931279BF13,  0xFF26D41EDEB16717,  0x717ED99B9E4D4A87,  
		0x463F8FA61C9E06CD,  0x51F6B0E5AF93BCEF,  0xB22964CC704C363C,  0x7D4D49D1973B14E3,  0x836EE4A0F1693D56,  
		0x6741D42B00C3C409,  0xD0A54661E926D116,  0x68F9FA3FE742CD3E,  0xEE04BE4DF06E52D1,  0x2A1D652DB6466C28,  
		0x0B5005E765C8A126,  0x3AF7E4D59E46CBC4,  0x1061DD78BB1D5A4D,  0xEEBB9EBC8A7DE2A6,  0x53D2572E2B09100D,  
		0x660BC66151156F08,  0xEC9C43343637B7A5,  0x783C0D74AEC411E0,  0x31465DD042BA246E,  0x2737469DAC0A7F91,  
		0x2F02708242092A01,  0xA8CDF652345FF5EF,  0xFB5EB1C305EF2B18,  0x822E768EB6D0F2B3,  0x0584B80F51416C9A,  
		0x39973817A390D296,  0xC2B47076DEEA9063,  0xD0D3A22E8B43E0A0,  0x86887AF8F86F31C3,  0x62E5CC82D2C63E7B,  
		0x44BE1B892CA74DD9,  0xE23C626B617241C0,  0x49A299A7B01AFC26,  0xD527FE50AFEF379B,  0x71ED760412001016,  
		0x2DBDCC72F2C0C73F,  0x4CB9B1B8637D9A4D,  0x0B2C99130DED34F9,  0x247681315A7C78F2,  0x0680CB501629E2E6,  
		0xD810F1F4C5DF4862,  0xB62BE7D66825E997,  0x3E3E69F9BEB821DE,  0x241F00D917A2522C,  0xDBBA9D5D888BBC38,  
		0xCC182794EE342CA8,  0xCC70C7D63271428D,  0xACC71AEAEC99408D,  0x18F1C6412B721F8A,  0xB8B5627CC9BC3B04,  
		0x673F5E52062C9FD5,  0x3568F9F6079AD51B,  0x91DE1A66825ABC84,  0xE9FAF905F05C45DD,  0x7C47C21AC68426D5,  
		0xB46B15DDED133F53,  0xC23D2946A8C26081,  0xD83AEDD533BD02B1,  0x6A2272A1630FD858,  0xFB65FE228B2F1733,  
		0x8B75BD52FE553914,  0x4293B97221C83080,  0xEB99094B46EDE87A,  0x74696260F6DE248A,  0xC691D150E607AF4A,  
		0x7027BACCA6F4C640,  0x1904AF346CEE368A,  0x3748C01D0FF56191,  0x96A17AC1E1D1052F,  0xAE9E099144BD3E8F,  
		0xFE54DA7D995E0131,  0x536F42E0EE714CB8,  0x6E04F25C4505398F,  0x0E6B5F4E8E3034A9,  0x6C3D6430836F7AD2,  
		0x12BCB3A85AD65DC3,  0x311F9394D74E7600,  0x3561BC69BCA2469A,  0xB30D97AF5842A231,  0x21E9E49F33B5B216,  
		0xF8F23C36E2468B1E,  0x5809DDE30E8070B5,  0xADAE4CB521938358,  0xF2F5762C824CC44E,  0xD01D250DC3B4BF16,  
		0x624308ED0240D645,  0xAB486CE83A00C4B7,  0xD617A2526047C312,  0x4CCBDC9EFE62F267,  0x7FAC014EDF76AB83,  
		0x4E13B5F998F5A48C,  0x6DBF4B5770A4DB29,  0x6205BCF02398DEE5,  0xFC530F9AE003B4C9,  0x5DCCF957E037CA84,  
		0xAA16BAC64DB488CE,  0x4AEA65638F397500,  0xBE2F0C33AB678F07,  0x14546A6EF50B119F,  0x408F2DBA6E3D4440,  
		0xFA53119F50771B44,  0xAFDF341FF637B574,  0xA2F51C784F01AE5A,  0xFBF63B7BA3BB9D9E,  0x015D76863934D421,  
		0x9D347CB0B7A9F886,  0x16D200DE8661D508,  0xA992136CF3C69BF3,  0xB75DDE40EDF78DED,  0xCA012AF5074C5A24,  
		0xCAFDA72B8C324482,  0x9FC5BF482E8F738D,  0x25BA4C5770892128,  0xE3B2440154D4031B,  0x8EB80F8B95E35901,  
		0xE2BDE6AB4483E794,  0x622CC2DA7F2BC101,  0xA62F7B014C1245D0,  0x0E5590DCE6978B48,  0x83A520F63D11EAD8,  
		0x39ED719A4275E217,  0xA483721F17016235,  0xE54D035180118007,  0xAEE0F2765088D3EC,  0xB845687323CDDB81,  
		0xFDCCF3378FFCFEFF,  0x17EE70A0A5398B7D,  0xE5D521E58719B872,  0x2B0975A246824611,  0x2EF6F55F960D0C17,  
		0x0B41BAC5B84A4D5D,  0xB8B1C3349EFC43B6,  0xCF7BC932FD845DD5,  0xA9B914389560824E,  0xD98C7A53DE99C8F4,  
		0x4CC6A4AADBAE1C7E,  0x4A17867437C0E9E0,  0xF1604E15F5D63456,  0xCA01455574039D8A,  0x33E01B5100572E22,  
		0xF3C25C833D1D6E49,  0xE5DF8DF141B524EF,  0x6A161FBD37F3C306,  0x612B3BAFD74968D8,  0xFEE74EE4F60E2C71,  
		0xDDA7F631B67C165E,  0x9F01C6677E0EEED6,  0x70233BDBC8A3CD53,  0xBEF9C72D97D3358A,  0x06C9113CD1D3C725,  
		0x1DE455AB8C7D850F,  0x2A04CBD36215D78D,  0xE4DF38BB6F501356,  0xDFDA3CDFCCA10FEE,  0xC1139C7BF1D6B9D1,  
		0x2E4B812A51BE9CE2,  0xFAC1EF7D6488CB2E,  0xD12A3581D63756C9,  0xA912FD177CA746EF,  0xDAB5E308B631B15E,  
		0x11CBD2CEF0B7BF44,  0x36B8762A41A88B98,  0x4FB14C4B1E9FD9CD,  0x1751F3760596A859,  0xBC48755EA10B322A,  
		0x13749255773C21C8,  0xFBCFD042255A9D89,  0xD311A2F86DECC442,  0xA6B03B285FFEF093,  0x9E481E985BF9BB42,  
		0x0C504FE712C8855E,  0x5567AB7EF06C29B9,  0x5A19EE7E1F52E559,  0x1165ED18416278A2,  0x08ABB3D5BF3B3B47,  
		0x016B7FA09A0829E1,  0x0A964D20DCA91BC1,  0xAC6392CD8F3C22A7,  0x3DB089DA8F0B56E1,  0x4F064B289B11F7F4,  
		0x5BF1466A1ABF73FC,  0x2198DA99798A20EC,  0x64E98C05A5E6C094,  0x46A771F3DFF7DE19,  0x0F5E138349460DEF,  
		0x8F495B2AF499F1D7,  0x7D2C3C49A1B964F2,  0x74004A1CAD2B4573,  0x948802B1755D2E34,  0x0D13F4B4393717CF,  
		0x92CF15AE47351C60,  0xDC49FE796020A57C,  0x708E7EAB3CAD2162,  0x7E2C6B6E4AFE2FB2,  0x7E084410E9FFEAF5,  
		0xEC907668D770AE92,  0x25662B041D21618A,  0x80DAC3F052CE2487,  0x75F42374FA78FCA0,  0x2C882FEE641AC3D0,  
		0x9C249EA4DB410203,  0xFBC4B652BF58B471,  0x3EC3F7E58325818E,  0x7A69E92045E9181F,  0x5CB1F553992B2568,  
		0xE17D5D243DD63AE5,  0x41939EE77FBC4ECC,  0x0C5765E414EF828E,  0xD563E14DD82E01DF,  0xEADE352FBCD8741D,  
		0x04690B7757CBE729,  0xBBC86EFB9A305DDF,  0xBD0075F17F04379D,  0x70A7D3114B38ADCE,  0x50DA4D9DA706D05F,  
		0x677E1761B95B0763,  0xF1A71474DEAAFDA8,  0x34E9A39A852F1916,  0x5FDC168D9D2D5873,  0x208044F7ADB25109,  
		0x2F2513B0CFDF68DC,  0x04B33C07E180B1B9,  0x49381A575F96AF5A,  0x7EA229823C0A7AB2,  0xCF2E6BF923375132,  
		0x428C0F0510D26E8E,  0xFD2BA028F65E78DE,  0x910E48F65BED86C9,  0x9E01A005FDDA193E,  0x6234CB83811AAF35,  
		0xF6AEA21E2F273AC1,  0xB75B3A16B9DCFE11,  0xA5F16BEB9CDD5BF7,  0xA62F3A5E37361B0B,  0xECE12DA37F8DCB21,  
		0x37A7DE5F54B2F6BE,  0x8C571325593BC4BC,  0xB78E9FCE50966561,  0x9222C564512BA31C,  0xEE405E44982472C7,  
		0xE26D96AD66719594,  0x089115B19F142AE9,  0x675095CF4144B9B6,  0x5B4A46BE7664697C,  0x6493CC25E5B59FB5,  
		0x8A7EE39E70E45C72,  0x71ABBD253E114AF8,  0xFAF9B526A2E49055,  0x3A773F1147D2B249,  0x775449C8B6A66AD5,  
		0xF9E818190BA62F5A,  0x9CCC4E653037370B,  0x12A5B51D97A3436E,  0x57B0C3B71997A830,  0x42E2D4049A80A764,  
		0x364FCE6CB312CAEA,  0xAC08FE7AE728D77D,  0x459037C8F3E79253,  0x6E8077A579AEBF90,  0xC5EC8D092C71D565,  
		0xA7C84B4579496A8D,  0x344B78893D25FA79,  0xEF3423704E9B3074,  0x023BA4FB1CD689EC,  0x4613EEFEA2266038,  
		0x0E604CD51CD73E39,  0xACAD3A719C755F1F,  0xFA625A65C2AC36FC,  0x58566B15F817BD9D,  0x3182C3D1752585BD,  
		0x7A2E74BE453CE1C1,  0x23F6CD8BA5C9AE76,  0x9B500981CF4731A7,  0x8974C9AD97B43B32,  0xF50C0C74CE6A2C8F,  
		0xAAED36DB7211F932,  0xD398C06919E7AF8D,  0xC227423AF6902F80,  0x59D2864E133B4AE7,  0x900B594D0337E9D5,  
		0x5F0B47DB67119F9B,  0xB1A25E4F0341A03C,  0xE69526BEEE98C8B0,  0x4A65880F239EE2E0,  0xF5971A9A1A3CEA31,  
		0x8235D0FC4E0012DB,  0x28E454A7C6A63006,  0x88638C83205DE40A,  0x6BFA8AF29556E10A,  0xFD71F9939703392A,  
		0x2DEBBA9803E5BF14,  0xD4CC298AF46132D0,  0xA2E6E4A52F834AC0,  0x7067C77AA3F3D2FB,  0xC339A79CDE07BA41,  
		0x8C5AA925ECAC324B,  0x050904DFF270148D,  0xC9B16CD1CB7EC122,  0xDEACC0A2C8507E90,  0x585A715DC7BA3E42,  
		0x6E7D0146F853EE54,  0xB9C2E4E70908BDA1,  0x6C0B2367A7A3B842,  0x3ACC0D83B2039D82,  0x9028470D2482D4E1,  
		0xE602C37D8A7CED20,  0x26C04BF99C3061BE,  0x1091C8BCA19CDF6B,  0x997C4B1D90AECE6D,  0xB729F1E04A40BDA0,  
		0x5E43FDCAC8B7EEB4,  0xA623E6DEF2F8B8CC,  0xDB20B454A8BC5D66,  0x736CAEC82746C671,  0x8BA881506179477E,  
		0xD34CF89FC8CC33F1,  0x3D0618C80F3FED6E,  0x0CEB56114D3E9D63,  0x46D1B7336CBBF8C7,  0x0A6E980F110FC7FB,  
		0xAA60B721C4953EA2,  0xB4EA453F1EE8D539,  0xD1D27213BEF7BB70,  0x5FCE2A65B1202B70,  0x4E0A6506EA9C131E,  
		0xBC52C1D2B4879964,  0x18F437D65CA138B0,  0xC56934213B017614,  0x51CDDB915F0FA2BF,  0x31FB566DA0719AEE,  
		0x0DE51B890B922E7C,  0xBFD13C71ADC0E5F8,  0x0B17DADA46831928,  0xD7380BC98BC2C2B5,  0xEC8E50D1FE145827,  
		0xB0912CF6A2F6DBD2,  0x47936D9101F8A209,  0xBB33D27B9D30DCDB,  0x601289EFE18A3F4A,  0x4A996ACBAB68E28D,  
		0x242B25A5291E479C,  0xD58FA288FBF9317B,  0x1674E14D7ABB58E7,  0xBD3495E63CCB5621,  0x20F41AFEC325A771,  
		0x40CC45CDA0F83E9E,  0x79671F9F99BA92CA,  0xAA034BC0F2A47DA6,  0x6C7FE5499840416C,  0x6CFA522FC7D6076E,  
		0x4ABFDF990F74B531,  0x1281FA5B044CACA4,  0xE91839CAD5B7E50D,  0x2B3228A5F25CACAA,  0xEB1960292ED7BCAE,  
		0xC193A083B2123FAE,  0xD660064C5EA700F0,  0x6A559E0A8FE6425B,  0x5918C64E439B904A,  0x4D9828768B7A0830,  
		0xC1DF121543585895,  0xF596E2C33AF316C6,  0xCFDB1F7608B037EB,  0x978799CAD0A37B86,  0xD8F3FDF2793A6463,  
		0x0D4B2E32DED8DEA2,  0x730CA56F484376F8,  0x0396EFAE50C6394F,  0x3EAE6C4F8D7CDFE8,  0x6A80C3017794FA8C,  
		0x5F27B4E9AF6D6F3B,  0x9FE4F072C7D9BD01,  0xF0128A616C4A4A63,  0xB5E1912EFDBEC9B8,  0x0C5A77877F793008,  
		0x45AE336C5D53CEBE,  0xD942835CB6A25D85,  0x925A4AF9709B3DEB,  0x1A95B27EE6D1559E,  0x5989F21CC60A0766,  
		0xF61176C080D2BE74,  0x140BB192104BA4A6,  0x9543BACAEB861CCB,  0x472E71B12B387BEF,  0xA07DFAAFF3926D12,  
		0xC402AEA17A2259A5,  0xD525FFEB31798ED4,  0x9D3D61CE989BE3F2,  0x0794835829B9357E,  0x1938FF9CF913D688,  
		0x1EDC6E36C62B2995,  0x8598BDB093BB4F87,  0xD139F86D449E27D8,  0x775D87EBFC4853D1,  0x8493B9BC3C1D27E5,  
		0x9EBE8C93DE464054,  0x515E31B0D10CDA4A,  0xDBE52EDCC5CE6F0F,  0xA95B52B1FFE3CE3D,  0xB2AE8E74C596B9E1,  
		0xD916438B36E2F945,  0x89E2FE69036D0A5A,  0x6CA4D478B0CC5F9A,  0x9FD5521C01541D2F,  0x981F74B4CD46EA09,  
		0xCD28A7CC2394D900,  0x9C69702B27269EA0,  0xD081C17C4335E389,  0x534905EF8D860369,  0xE52FA2E5D8734D7E,  
		0x047983C03231FF01,  0x4561A15D39E28C9B,  0x8A47A4CF3E8AA0CE,  0x90488D721B225CB3,  0xB9725EBAB7A36B1D,  
		0x1F85515AA8F653C2,  0x5F6F129252F8937A,  0xF794BF0BE0FDCA50,  0x25DCC56BBED2C1EC,  0x6E6C8930D82000A4,  
		0x3BD4F80BD3E5B60F,  0x2446170355137294,  0xB7F433C21183711A,  0x0E9BA058FB67E701,  0xF25B8F9BD234A650,  
		0x4EA7D90247B44537,  0xB693F0AD3C4DCF72,  0x1D375CF6168D69C9,  0x0C23BE37F88F6928,  0xBF6F1D81662765A5,  
		0xDBCF530B98AA9B7E,  0x4D28D7143D8B956F,  0xA0E8048577FEFCE9,  0x83D32B0CEC7D246D,  0x1BAEC92EEA9BC26D,  
		0xC24B8D31B43C257E,  0x75BEC10169281DD7,  0x8CEE1D5A637FC5FA,  0x659703EA7BF6D335,  0xDF20971F4F15896B,  
		0x34C4CC39DC2540E6,  0xCAE52F2C9CC3CA81,  0xB6D796353F4FC1FA,  0xF98B942C1711BCAB,  0x682FA81770FC88C1,  
		0x6C59CC09FEDEAB3B,  0x1CE0CA5AE4805FB0,  0x031741A212AB8606,  0x7B488B34B2BFB90C,  0x52A15EBF53B3C0D5,  
		0x5DA33DBCA8D5A9FD,  0x99423693F604722B,  0xEBCE61498F416BEB,  0x3345C1B82AE9C726,  0xC494C4220CD85762,  
		0x3A5251F95C241D85,  0xAE4089A265708DC4,  0xC74EE620027AB221,  0xFAE0E39AF9B5C39A,  0xB332981C0B5CA14E,  
		0x4F916CA944556342,  0x20D1F6DA8768480B,  0x993D89EE404B2043,  0x32D6EC5666C9B7E3,  0x46C0918054A51D9C,  
		0xE74A6C46A089B4EE,  0xE9EAAC9EBBCF8DBD,  0xA7A8841D0EF56C58,  0x20DD8CA8C702C115,  0x833A95D3D5828B4E,  
		0xE9583477421E0051,  0xE37B205FD397E94C,  0xE9F290BD40D361C4,  0xA9942E67C3D1E61B,  0xABF4A5B02B9E9593,  
		0x0A888A33B87ABAFF,  0x3D567A3AE1BBFA95,  0x1F68809334041FE8,  0x57A4259CDCD13E0A,  0x99F5BFD1AF7B18A3,  
		0x9FE77F58DBBAE291,  0x66616F95C107D35C,  0xE75DEEEF9B775F0E,  0xBA5F0EE209AB88F1,  0xAEADFCF377DF245C,  
		0xCA814A34E39A98E6,  0xD7739588995E50F3,  0xAAED491C0194F5FD,  0x8466498341A63BFD,  0x91ABFC5F53E0B5B6,  
		0xB0FF8AD77EC8DD65,  0xD971902FE098044B,  0xC0746727B2F37EE3,  0xA576C4A293142FE9,  0x62FB23CC5E792214,  
		0xF409A6052174C123,  0x11BCFDBE1AA9B225,  0x27C1A2704F55FC04,  0x5F7D7159DD5BFB92,  0xA8CD9E4891E3FC23,  
		0x1FE8F60D57E9130A,  0x3A974232B3A237A4,  0x9BA1CC83F7D05C7A,  0x6002DE47955F6014,  0xF58F7EFC23E455CA,  
		0x0BD57C3195E0A575,  0x48960702EE9334D3,  0xD559A81DCB021EFF,  0x75C8F5DBC45D5E93,  0x1D1DCB481517DE61,  
		0xE4512173454A4DB4,  0x3CB13E32B88A4581,  0x3FA8BAC0E0BDB8D0,  0x888E306919BD6C0B,  0x587218175CAB3D29,  
		0x46E47C05BC7A095C,  0xFA2049EB13D390A7,  0x3AC187F3CA29C07D,  0x45C56727D2495657,  0xD31DF14B695CA74F,  
		0xEAC9A340742832C2,  0x3297C5D9E529BF1E,  0x72F4D7B4EFFBB9DC,  0xF1351C5ACC242428,  0xE21998D42CFC5651,  
		0xCF469D9354AFCAE7,  0xDCDCF61794E9EA7A,  0x119250EB3FB00518,  0x9F7A2D80E1E0B54C,  0xDD322AE3EAA60DD7,  
		0xEF0C22F2623489F5,  0x671B881E0F6B5348,  0xD7CDBC90F6F0B6FE,  0x1A0D207059E26DA5,  0xF2E8FFC21540A23A,  
		0xE7A886E08B10FEAB,  0xE0D8737877ACB0C0,  0x70C211239D34E1B6,  0x3C0087FF99A11EC2,  0x0F7FF7948D8BF413,  
		0x9C14169CB6738103,  0xF5A279631E9C9E4F,  0x4FFD17CFFC9EDA36,  0x745B040F98FBFA87,  0xC3693A2E5E9D0892,  
		0x53609D139099490C,  0x20C491454C65E455,  0xCC730CE7C9D3ABD5,  0x4252A812D332C617,  0x214F7F6F4B9BAA92,  
		0xB73F21318CCD6414,  0x4614EB10C3201C64,  0x7DE79BDBD44B97DC,  0x136B69AA21999181,  0xB545D4854BC1BA05,  
		0xB43E58C795E4864D,  0x364DEDD1450567D4,  0xFCAA4566B9BEDAAE,  0x4D381F41FF4FC6FB,  0x1CC1AED185A08BAA,  
		0x5415560A0C1D45DB,  0x64149FFB663ED290,  0x15BBC5FA774DFAEC,  0x4C735307EBF0642F,  0xDBF8E095692CB43A,  
		0xB5255B878646E3F8,  0x8822AAE40CA49017,  0xEDDD45351D4F89F8,  0x2B8A9BB3B8802A6F,  0x5BF2E2D86611C806,  
		0xEFF92F78183C1668,  0xF6FC4741D0FBB9A3,  0x2944F91EBF94122C,  0x159F651DAF172B59,  0xFA3CABA45B83B319,  
		0xDA842DB26DF3D99F,  0xDA860B63FC2C429F,  0x45916E6EDA5F7C86,  0xDABA8B8BA49AB89A,  0xA12C35737F1D1CC4,  
		0x29F2184C9010BDF2,  0x17F40220F6F457CD,  0x861614D8181E7AB4,  0x77838BF6B083F424,  0x90BD095783643513,  
		0xB1FFCBE9B674C408,  0xF6F7449AAA8F02EA,  0x84CE06A017BD2421,  0x2D5E9340F7A215B5,  0xB88B0CD6D1C5B4E5,  
		0x5CE186BD73600920,  0x7768D683296990C1,  0xCA2B5D9C0534A698,  0x5D623910F7E30656,  0x7B317803A39B5481,  
		0xDB35F56F9DD69540,  0xBE57A37D1DB17606,  0x8BE8AB71D8D46545,  0xC6C3F39B8A2FE89B,  0xD691F94EE6C0FAE4,  
		0x4BE2D6302CB29E9F,  0x558123E97EBBD98D,  0xD8C4FD3EAFD922CD,  0x324FCACFB835E316,  0xA4E89B0411522657,  
		0x163E15B1870B6527,  0x752528E334AC2BE3,  0xD93D8C650696B8AF,  0xDADC6D232A407BBE,  0xE259FA552DD36CA2,  
		0xFB38F0FCB93DE200,  0x83B0AE923BB97C90,  0x022B7C7A8E815580,  0x64F84E827D375CD6,  0x5EFF1C4D3D6F9EBD,  
		0xEB9A9E86C52B0176,  0xCCC732B5ACC6782E,  0x90AE0DB292FEC1DA,  0xB18E8446FED87D91,  0xDDA58C0DFD926B0E,  
		0x36187744EB66263C,  0x9A51919D8E47C334,  0x772E3CFBC0CE0672,  0xB3D8B3C9532F8445,  0x82D91B78C2F9BE4B,  
		0x3E93CA7E5757B951,  0x6191CFA0481160BA,  0x8E446ABFAD8240E2,  0xCF56C7A9AD92CBA9,  0x0AE03529538DD035,  
		0x3CC1C89AF415724D,  0x5637B837F4077E57,  0xBE9E126FE4988D17,  0xCA05A3F0F776EB74,  0x8528EA253FEB0EF9,  
		0x307B7AE8381E57D5,  0x850BFAEF4741B5CC,  0x7D26FF5988FCBF62,  0x454B447E14CC9C1E,  0xFB182671A40821A0,  
		0x50C8EF2E23ABECB8,  0x9172F3A003B95387,  0xE1A4A4A9B843CC8F,  0xCB21762DB10D5FA3,  0x7AABB77E7C984E0A,  
		0xBB25500E7168E256,  0x812EFAC2FFF658B9,  0x070B224B06BA4B44,  0x9202EFF7C5C572F5,  0x364F2D1F287C4A20,  
		0x791088DBD510D704,  0x3205B43B45473C7A,  0x0DC888FFB0E643B0,  0x05E73E7502C98344,  0x19F33B6FB14E1877,  
		0x54E2476E9D160A1D,  0xE5BBB7E2854117BD,  0x71A2659DFE604FA9,  0x75823C629FA3ADA1,  0xF8FFD361B556B57E,  
		0xADE3907D1BE4E86C,  0xCB14EAA81A78176F,  0x5A912193AA89F7B4,  0xC1BF6BFA03C7F539,  0x06F970F53A8599A0,  
		0x4A998F88E286A6E2,  0x8E6A07FD41E6E9F4,  0x9900553517997348,  0x4E3C188226F71CD2,  0x9C83634F396FC1B0,  
		0xF1C45C6702995F50,  0xAB251721F96D525A,  0xCF28F246ED43F254,  0x0F158A2A56D53F5D,  0x37E2E2A5699FA84F,  
		0xF71FAF30627C4E63,  0xF19FED3A326A4CD8,  0x79C41F3E488CA4F4,  0xBE5AFC6B5CE5B52F,  0x6F064BCE2CD50C74,  
		0x86ED4A200DB55B31,  0x2E3C05492A307000,  0xBC0220ABD3AC004A,  0x2DAF6F527EC06DCE,  0xE03BF892C2B67C5A,  
		0x8BB4AB1764CE86BC,  0xD585648A88939CB9,  0xCDD6A73C9341FA32,  0x80F02C1AD5DEE1B5,  0x950738C928C08187,  
		0x3E2786DC3F460D3C,  0x874934BFA1B8B57D,  0xD76AA259D5BB6396,  0x320FCAE83396C19B,  0xB3271F3807C1475A,  
		0xBE9A139FC6A67472,  0xAEB2034152CE0C01,  0x4CD5B04B54300900,  0x384D6199893F86C6,  0xBBDF3C60AF8A04D7,  
		0x7385D45E20059BB1,  0x12FC2FCCBEE807BC,  0xE42537903EC55503,  0x74F52EBFEBE83CC4,  0xBF59482F55DB8D5B,  
		0x8BFAAACD63EB124D,  0x725880012F466949,  0x8FCC4184256A4539,  0xF3B54290320ADB31,  0x3C9D618C99A77559,  
		0x5AB7F6784B7244A7,  0x893CE499211FB3EF,  0x08833B30CDEA8AAA,  0xE84DCE4A8D5F1AA5,  0xF3687308FB1FAE6A,  
		0x24E3D27D0BE24871,  0x87BF772045694281,  0xA8A33C3E0BDBF344,  0x2CBA03BE8453F4BF,  0x9286DDFD73D5E06C,  
		0xE913826408A66EFC,  0x2BBB0F5A543D5B12,  0x0D26B09ED5ED1595,  0xCD815943B10C7744,  0xC7D942A1722AB870,  
		0xD1D9E1E346EE6962,  0xBBF86B3A1FEFB3C6,  0xA2B8C3331F4644E9,  0x26048BD71BC55003,  0x4AD32CD222B662F4,  
		0x2117DACB836A7C77,  0x21995814EAD54FEA,  0x96765025CC02D6B2,  0x7BBA800BA1EA412B,  0xA882C5EB8405E0BE,  
		0xE4999295D29E86C8,  0xA136F3A9B6486294,  0xBD5B7F63A9BF027D,  0x1FEA8ACF852AC783,  0x15C85A13213BB48D,  
		0xFC189D61E78DE65E,  0x6BFA69731DBC382C,  0xECFB071BFCCF9BA9,  0xEBE00B36BF3E649D,  0x9A41CE2C19B8FF27,  
		0xD8DD5D3D494D8534,  0xC2C84044A5DE5A6E,  0xA463D7E5609009CD,  0x4D2036CA87946C6E,  0xD61B83A3F1740285,  
		0x84E5ED7D9C410610,  0x4743AB7AEEF6FCB3,  0x8942D5FFFB6C365A,  0x9D36F1ABC099BC73,  0x8EA4D43D6C8CA0B3,  
		0x38897057F3B4A53E,  0x099C77B63246C642,  0x28FC28939E823D6B,  0xECFA784BC1489380,  0x148C83BD624C6388,  
		0xF3AE5E380DBFF56E,  0xD32B08B7A65D59E8,  0xD18E7065B7DA2610,  0x6B2F74FB865E8BE8,  0x171AAE7B2E80D61D,  
		0x1E675C460CF9B1A7,  0xCD72206B070DEA08,  0x76A33CEDB6B30A4C,  0x0B1EE877B15CBAC8,  0x0CF0CEC6A9151A17,  
		0x89FE0A2241423F06,  0x0234AAC70F5480C6,  0x8476A491E907BFA6,  0x8CA4366BEFCFE615,  0xEE5935885C31D2BD,  
		0xFDA0B33054D47566,  0xD625FF134E745A71,  0x98C3A43B973EBED7,  0x8826E1B1085C415D,  0x41707EB502AE6348,  
		0xA7AB2AB341CAB468,  0x9A06E002311B8226,  0x75DE1F39C210BA36,  0x50DE447F66C8C2EF,  0xD31AF33096045296,  
		0x6573E516EF9A59D0,  0x2946E548E618CC9E,  0x5DC24E660C16DDD2,  0x15A108F981235053,  0xB27FA4F32656805E,  
		0xD0A1E21F7400C110,  0x7B065349165B8135,  0xA4EC3EE62B113009,  0x68F624957969E704,  0xDCF6583948032297,  
		0xF222C4BED10AE43A,  0x83FF92FFF5148639,  0x9F2B79B68C9AB0D7,  0xA4084900B691DC6B,  0xA8233D11534B5539,  
		0x69EE4B5B73ED02BE,  0xF8F3BCD064B13743,  0x6477FE0B537F8FDB,  0xF6B26A8A3B18824E,  0x24FCE001F68C1C52,  
		0x1FE3B4F0CCE60BBC,  0xDA8751EF0ECC866B,  0x55AFC510A1867131,  0x2CACBAE8D371624F,  0x9559D25F7276AAB5,  
		0xDC0929A0B10DE43F,  0x69CAAB164A20FA4B,  0x3D2D66FC96A138B8,  0x76CE3D13085753CF,  0x79F77F6561767EB8,  
		0x34A7D2D4AF6F5B07,  0x5EB8D7380A420279,  0x14EAEBF62502BB54,  0x5E31D0543F857B5E,  0xAB0D2CD86E963367,  
		0x63541ECE73D4FDEC,  0xF5ED49FBEC6F08E4,  0xE3E3ED667A4C1AFE,  0x5D9704E0341902D9,  0xBD7B0363800E579D,  
		0x83CDBE05B81ED76E,  0x811421192F59D515,  0x58743E08EBBCF848,  0x5A3242563752374F,  0x6EB01A96CF51AA63,  
		0xEFDA4A9E7B45A76E,  0xE6AA574A9589A977,  0x31021216F4CDCB3F,  0x141D0A5B61570C28,  0x2DBD3F9CC5D7BE08,  
		0x4D62954601EB858B,  0x44581893BA2F15A9,  0xA381DE7BD402C9CA,  0x3FBA7582F3D4D73B,  0x6BBE7E6116F816E8,  
		0x04D2FFAE9A03008A,  0x6078D3C2983A7FF6,  0x117403650866081C,  0x93B3863360CBE83E,  0x71F3E0C852AB7BA6,  
		0xDB5A7390D6AA6D29,  0x0E073D71E025C51E,  0x8870F5448F0EA0E5,  0x9AB9905853FA28CA,  0x309505A36697BD24,  
		0xB90ABAF08FC652FB,  0x96CAEA18A196AC66,  0x78A2A296096EDA54,  0x774E37A7E0D0C1A4,  0xB63587D2D05E03D3,  
		0x342FC08C6628015B,  0x97981232630A67F1,  0x9FCA6FA200C14C50,  0x862D52D6C351E493,  0xF8A4DC8349595B7A,  
		0x153FC21FF6CD9DA6,  0x1A1E2E20A5A19DF4,  0xE6FD193637DD3E99,  0xD049A4E3DC92FCED,  0x0A37036C74D2C913,  
		0xD5A6154125CB9EEE,  0x3EB2E0E8FC3E1197,  0x88E62BE55332CAE6,  0x77B55829880528F4,  0xA1C7B987062A54E6,  
		0x8EA7A275247DE9B5,  0xB7FD91ABD8CDD971,  0x0C15FC66DD7E42EA,  0x7079B17F47CCC9C3,  0xE5ECB35050DAB5FC,  
		0x5DEC1E35C292BA89,  0xD8CB8E38AC7CE379,  0x631489351D98D7DA,  0xA16231D19DD302F0,  0xA28ADF99BDCAA46F,  
		0x1C3A3DD33900CC52,  0x31EB4E787C1C0F6A,  0xBFF663B047CF3D7D,  0xCFDC69913D7C4337,  0xD9F9BEB2AB0554D4,  
		0x972B5AF1157EA946,  0xB98BA8172C6AE215,  0x9741A358092D49A5,  0xD40022D4745900CE,  0x3D8591057394BAD2,  
		0x3F06AE44735F3C17,  0x65B580D86EC41538,  0x4F34F8FF1F1AD187,  0x1B1EB08E020F9F31,  0x420591BA490D1974,  
		0xD3927427398AF985,  0x45EA971D7ECFD501,  0xB947B85C3AD1C9BD,  0x3ABE0D0134A7168E,  0x245E1451B05006C7,  
		0x32C169A59E21B77B,  0xA17E398C865FF5B8,  0x4A83E3F7F3FBE662,  0xC31E267AFCAB5FB5,  0x9672711323365B36,  
		0x403551AF4271E742,  0xA177F6B4A6DE3AE7,  0x1FB546483D5A7294,  0xE301666F44A9BA7A,  0x75E5B0BA40A6B18D,  
		0xD5DD9DF6743231B6,  0x29C69A9D65C7A98E,  0x4ED7AFEAC92917D9,  0xA6E69FCF6F54B64D,  0xD39A2225B294E8EC,  
		0x9DA2F3ABECAB6642,  0x0A463E866BACC0B3,  0x028D8DD17E7D5272,  0x525B4DE53EA6A04D,  0xFFBD7F4D2BCBDC9D,  
		0xE9F07DCB5E4FE5FB,  0xD217F6C8F2DCEC1A,  0x38E50D3388F60AAB,  0x2B2770B232E120EA,  0x509ECE95C5CD4F3A,  
		0xE7DAAB19791ED5C2,  0x7C08DA1C4588B387,  0x7F95485DEF95FD25,  0x8AF955EC2798EBD2,  0x4F3ACB85EB2E3ABE,  
		0x9FC387F7C7069CF7,  0xC36B5974ECA9E196,  0xE7A998E9A4988685,  0x05EE7F0659A808E9,  0xF9044E3D6F8279C8,  
		0x065179584A34049B,  0x5E658EB5BA7F9F36,  0x5F04D76D0B6E0B9E,  0xF69AC3E3C0E527E5,  0x78D01693B10585C6,  
		0x1062818EA5C6AEF0,  0xA836C9DA05582BE7,  0x2FCE2C5276F74EF8,  0x8574E419E3292829,  0xA4AEE7E15E485A26,  
		0xE1FFD0024C0589F5,  0x9F1AC6E2350AC750,  0x8FFF55D26B87F7EF,  0x7AF50E730878D53A,  0x12FE1742F1D063D1,  
		0x379981EEF1452D03,  0xD7143B758EA86F2C,  0x5725BC99D540FF41,  0x071AB286E2DE7D52,  0xFB8DA277278A4356,  
		0xBCFB76BA7E946DF7,  0xD08A6B862A797706,  0x02FB13FC4153FD50,  0xF29BE14EBE040C5A,  0x23E399D2B3D719B6,  
		0x46C0799ACE022E4D,  0xFC38839883A47418,  0xD6286EDEE55038D8,  0xC22F0B396DA277BA,  0x371A92D7AD7EBF5A,  
		0x6EE1776E6706FF20,  0x225D9E779E465470,  0x1B481BCE3B0D570D,  0x94EC5750BCAE08B3,  0x30C102D22805BDFC,  
		0x425A6A2FEF63D1FE,  0xD17D6C42CF79DD88,  0xFF3BF8B844675324,  0x6AF0C14E93310C92,  0xF6091057B3D65C3E,  
		0x3D672ED94413CC2A,  0xD65D37F89C310601,  0xAA30326B5FF2368B,  0x781D5B784E250EB1,  0x3F52826F08754EA5,  
		0xBBF39BDAE87D2DB0,  0x6E85AB3FE77B980A,  0xC2BB35E5E87AFAC0,  0xA73713DB2466EA3A,  0xAFDD09C1D781D867,  
		0x3AA6D2D969DCDFA1,  0xF94579E00C8F9D1F,  0x97B2829B0CC1DFC8,  0x3484D971F6B30D33,  0x0BA8EE70F331E582,  
		0x35D3DF433D33A775,  0x808E15CF6D739520,  0xFD1CECEB5ADFE13B,  0x4979F26E12F8CBF3,  0x70D1D7C85B78423B,  
		0xB54A1E88EA9DD99D,  0x8041A551B4E6EF44,  0x48A01D3E77805D05,  0x3144FAD8417AAAE3,  0x5C3334663AD999F1,  
		0xF183BDE58D15B575,  0x5DC330F89F7C5986,  0x1C3BB1EA9CCD523B,  0xCA7E897FDC99D742,  0x0C5A860EFF1F9D5D,  
		0x3B7CD0D1F3B5AD35,  0xD1E32677F2835F10,  0xD9EE22A588AB7577,  0x32FF2372B0B83233,  0x3AF0B7647ADF3C36,  
		0xFEC6A27996D83917,  0x1C7DB0EBE3D834CD,  0x3BAE751F9CCE495E,  0x67AD8AC1B9843DC6,  0x8FB5847CC27B800A,  
		0xFA96D98811AAEAAF,  0x4ED3A0C4ED652136,  0xEF55235A701C5830,  0xBED178414F7A9310,  0x304DC8FE6A4DCDC5,  
		0x009AC2FB7E0EBA0A,  0x5D8D4AB1093DF200,  0xD84594EB87CB0C61,  0xF625BE9DB58EE94B,  0x186BAB9F41056D63,  
		0xC4B7C6E0E9EEEC78,  0xFD2491C64F72D527,  0x19DD8D4D6D008BA5,  0x60CBBF39A0E60788,  0x0BF357F0F6183B41,  
		0xC2EF7291D45435A7,  0x53C3FEAAA73E4431,  0xF228A677190AE743,  0x32E41BFA7B158D63,  0xD6439C664D9685A2,  
		0xCD1435742E4A445C,  0xB30B44B39E8367E4,  0xA3C3BF1DD26A7B78,  0x5F31B42534B260F7,  0xC3DADC48A31337F9,  
		0x40321E9193B11984,  0x343A2C472E906F1E,  0x9DBC17784217048B,  0x90E1BDB2F01468CF,  0x8712E9A360800B8C,  
		0x9D7E83C2E3ECB7AB,  0xFCFD5165577AB76B,  0x4C24B286AD18C173,  0xB5464E2529402D76,  0xAC3EECA3DFE08026,  
		0xA3769B6C61BF6430,  0x244E238E761B8356,  0xB759B3C43E1F89D3,  0x70D105F75FFB1A73,  0x4F060C3A5C7E46A4,  
		0x05BBAB87D74CC41F,  0x4989E2797D475F8E,  0xD02B2CCA5B4B53CD,  0xD305C4EA8133D1A4,  0x658A5671102F063B,  
		0x44E5B071818FDD71,  0x4E247BFF6FD2467B,  0x3711DDD5CC063146,  0x9D2B0B254FDE80B3,  0x0B582606D7E083E6,  
		0x617CDAF1C6165CBC,  0x2CF703F520330D3C,  0x4AFF9C4A2C6F6A3E,  0x8D1B70C8D526F100,  0x2A2E9FECBCD1F904,  
		0xDC4967D1B616EF79,  0x947E4D8CB76FDB98,  0x9A12CE9706F09ABB,  0x1A85DB6DCEC8F76B,  0xDA224F069CD6F313,  
		0x4E5F8A2DB18D9D13,  0x298DC9C818A6BB81,  0x8B81D13D44B9FC63,  0x9B87A95179AD1F6A,  0x175179E03F54736D,  
		0x8AF1EF64A76674EE,  0xECFCF44FA56E44AB,  0x68F9DA330ED11387,  0xF9B4B0F4E1103FE2,  0xD9CE386E5E7AECD5,  
		0xFA1D2A7CF5EE6A82,  0x01AA58217401E5C7,  0x30E0E8D7CFD10783,  0xD7D46F3B16796884,  0x228D2D04FBD1D41D,  
		0xA4DA52470AAF5BBA,  0x16719DDDC18CB5C6,  0xB73CA9DB90F82A45,  0x80FC0AE413B33F5B,  0x2FE15DD697C5DE47,  
		0x9419DF60765EAE5F,  0xB80F4296CAEB9526,  0x5F6641F88DC19EB8,  0x775B5BE88D174E12,  0xEE818F2BD0EC024F,  
		0x12D7A770FF9E5AFA,  0x41A653F7E270BB80,  0xF9FF78EF6C651C20,  0xC5A99D3B5BE5DC3C,  0xA33E69C5564A38A1,  
		0x56CC8C32B14DD146,  0x439E96B64E0ACAB9,  0xAF585CC6FEA8F801,  0x8D0C06F014560486,  0x99C05B2ADBEF9696,  
		0xEEC981F375463A8E,  0xD80E5F9F0301B986,  0x3E13D3054E2B1367,  0x21A85CF7EF08E6E7,  0x6BA04467FC24681D,  
		0xFF0254DC2E0EB6D3,  0xD7857E9C70B33759,  0x4A9AEF7C6B9A81D5,  0x9A4754924108FD53,  0x09A677D7CE40C960,  
		0x712840A65D6F5D0C,  0x0716CD6A6246138D,  0xCF8773EE1FD8DB71,  0xC3342C7D807DFAB0,  0x20FDBD59B3330B4C,  
		0x22C39318F2BEFA89,  0xF212FCC5E0C58131,  0xC4C115E5CE62601F,  0x89CB1328FD7FC8CA,  0x96F9C228E15C7E7F,  
		0x56F5309326B6F12A,  0x0A5B0442E7A539F9,  0xBB0D26CD247CAC1A,  0x699408F9D4CBEC94,  0x1BA8C7F00751FC72,  
		0xD1AD871ED897E9CC,  0xE4D1D75E579219FD,  0x868742EF6DE2CCD7,  0x4455951956A71583,  0x36AD00E7FFC89400,  
		0x29FAF37CCCA1F5E2,  0x7CC2F6858B91A4EB,  0x6CB819FC907A8F61,  0x2ACC08CDA4C480A6,  0x3368B8898DE3C8A8,  
		0xEED9E636ECF47C03,  0x322EC2DCA92D6CFA,  0xDB3817EDB1FB8F8F,  0x4E8C74EFB05D21A6,  0xFFF2F92F83849414,  
		0x8572267F7047A4CE,  0xF29D2ED1B3BF539E,  0x89E2967DACFD35EE,  0x1D80F0D4E76C8C47,  0xCA71DCF18EA4FCD1,  
		0xDAF3103A9E65A95F,  0x29D59DCDF65481CF,  0xCE4390183FF8E0AE,  0x44DB6DD5CA3B628E,  0xBBD1BE3FBD8DDCD9,  
		0xE8887FBF44F1709A,  0x870FE99C9229FB39,  0x27C9C7465985E38E,  0x39CD56B98E7EB2A2,  0x1B08EE0034574EA7,  
		0x2DE0D9AC8765C9E9,  0xD71A7E46309029F9,  0x335B5C0127AB6832,  0xDE6A0FA46A9B8998,  0x1BAF00FE1E4B8E44,  
		0x60EC89C191A0217B,  0x6FBE86FB2F51FF7A,  0xA74722D0A49E02DE,  0x7592C54797A4DA0A,  0x9DC7F91F8B7DA86A,  
		0x6C7BEF750341E9B5,  0x162DD072E0E3787A,  0xBDAAECA5D174ED26,  0x3DEA97632F5F7126,  0x0DD707D3D3BB657F,  
		0xAB702B0A830D4805,  0x644E98D0623068E8,  0x323FDBDAA872F7C2,  0x7ED6390F13702425,  0x8CE02182A9F78FF4,  
		0xCA04B71E66090C72,  0x377EB9637F072FE2,  0xD54F7BFEBEA90A3D,  0x27F19F19D2717316,  0xDAC56A5B50656E71,  
		0x81F00D38B1594EE5,  0xF67CFCF79B851F77,  0x52C4615C0093825F,  0xC301E36DF36E680F,  0x705E1E54ABF7D645,  
		0xF09926B9F55C81B3,  0x8697DD2B89C190EA,  0xF6F56DCA0FC3A526,  0xA4A94E634BD4C23B,  0x8603C1AC75436F54,  
		0x16243BD8F93BF63A,  0x8CBCE4B89E4C8DB7,  0x38888D4173E900A8,  0xDE6DE46A59A83CD5,  0x5A5E094DA95F82C1,  
		0x31B8D66AE62BFC9B,  0x0CEE700E60839431,  0x2A8EC2A02F1CC99B,  0x481FFC438B7DAAA4,  0x0BB429DF90CEF779,  
		0xFA989CCD422E87A9,  0xFEE01738CC30C80B,  0x693D918F3856AABE,  0x3E566C98CE215BF8,  0x32454B960A3D15B5,  
		0x21E276DA72786CDC,  0x0B7E037743322BE3,  0x955AFD20BADFB637,  0x7312EE55B2F428AC,  0x326A27B396ABD9B0,  
		0xBFFE7620299C2868,  0xEC11F75D1B08347B,  0x2585C01FED5396BE,  0xE273AB9831ECD6DF,  0x7D7BE20119BB97E1,  
		0xC2A8D7B69A6E6C28,  0xC1B6ED0FFE81BE56,  0xCAFFB96DDE233093,  0xB006F571694F252A,  0x69BAFA0C6568E3F3,  
		0x0F2A73B9B6D2E6C2,  0x257812EA5F83CB1B,  0xF89D363E774672AA,  0x64A9E9794BA99757,  0x14CE512A8C770911,  
		0xEF1C539F9D30427A,  0xE72C5C5551F930D4,  0x2B3DE5E93F2BE746,  0x17A0987AC3C0653E,  0xE2F5A6586AF9293F,  
		0x517C2E7D5C078AEF,  0x6B0ED47DE1452C22,  0xFE7DA6EDEF0F078C,  0x3ED43DC626403A9A,  0x1181BA1EC9CDAE18,  
		0xD133FFC36FDBDCED,  0x199775A3B05C2231,  0x6FD2FD7D87FA93AD,  0x8D994F1DF1816E86,  0x1CBCDCB5C4B47FBD,  
		0x241399DA465FDF38,  0x9AE45043ADD1C820,  0x552958C207E9CF0E,  0x62721996F8E65773,  0xCE5174BD8F5F8EA1,  
		0x0DE6F8AABC6765FA,  0x942C1CB043BCEEE7,  0x125D6B909E6C82AC,  0x975963C9CB96D4CB,  0x1DC1D8FF5CB53CAC,  
		0x082378F3C194A1B0,  0xE79A602D21D9FFF9,  0x73F2F2BAC93F3D15,  0xAE091F8576917B6F,  0x28F20A16628E35B0,  
		0x12EEE799C626CB4C,  0xA9E3000F043D54C0,  0x26AA74052A4D7AD1,  0xA01F124A7F7FAC5E,  0xD8AB7CBCCCA788B4,  
		0x5DD31516E3683219,  0x242193A82B7BC58B,  0xC0FF6AA2AAD4E923,  0x3253C01A7B1CF04B,  0xCA5EE2961D758BD5,  
		0x46B498263ECEB496,  0x2C49975C5B069A5C,  0xDC8FCA8911E3EF6D,  0x3ECB62F56F82C4BD,  0xBD38B742BD1C327E,  
		0x718F083837B860A3,  0xB1E34CB8244AB32C,  0xBBE5B3036F3D8F8C,  0x5FDED798DD7F79F7,  0x791F1DE2636E784F,  
		0xDAAF0082A5021001,  0xDD88224462B00F16,  0xF787A7B9E89A63AF,  0x68D1DD6BFBEAE93A,  0x22F8E11618AE7AC4,  
		0x774AABD4A7AB16AB,  0x8620949856F81764,  0xFE3A0AD4EB2580C4,  0xFE7CEEE6809A06DF,  0x72D7B8D954CD6EBB,  
		0x8C87EC473C8FB438,  0x00BFD3A342E89A16,  0x4B8514746F881DBF,  0x566BDD811E2FC1BC,  0x12798A048363C441,  
		0x4623228E3D0778A8,  0xBD0A10DF9AA4E38D,  0x51FB319467AE954A,  0x5D03789917478F65,  0x0BE6E534DA38B907,  
		0x1C9C1D4F5899FD1C,  0xC98155980ED5738D,  0xA8020802C4BEA165,  0x20223CE979951BD1,  0xAC931224E0BD2B22,  
		0x2AF6457D566528E1,  0xBF24C373AD001738,  0x5C3BE38862AB2F02,  0x0B0741017C676EAC,  0x966E29E2BD81B9B1,  
		0x1AFAA49D1117879C,  0xAC0CFD625C3D1974,  0xBE11889AFC60AACD,  0xD6DEE8E56C7A74A5,  0x1E86F14F16289AE8,  
		0x33EA2135C9998CA1,  0x79D4576124777797,  0xC20F8782413344FE,  0x79DCE062C4CF2625,  0x1017CF366896A0AD,  
		0x28CB41F2DF2E1A4D,  0x8E2DDC872531293E,  0x3E4572F9A5A2DD5D,  0x102340272A291EA1,  0x46E52262AB9156D7,  
		0x938D46127742720D,  0x286A7F083CD7F133,  0x28A5E5833FA2FCFA,  0x47E2C54B97260E77,  0x790DE2A5B2C82D59,  
		0x0D0C58354701ABB6,  0x9DEF63B696881263,  0x8980B9B6F5FF5FBB,  0x81A9FEC61EA2E1BD,  0xCCBD9405F8F5E070,  
		0x82189F67DD0D42C0,  0xC9E6C8D02AECBBB4,  0x79ACD82D6DB7FE25,  0xDB28165A24CB43C3,  0xC8FD46D0092E2A6C,  
		0x62E1CA6BB1CDA466,  0x6A12078A5B2021B0,  0x3E58E33A85FFFD76,  0x5C9FD024BC6A8BC4,  0x9262DB593E058880,  
		0x408AD1D36BF09FD6,  0xF295A2F4D6B68A8B,  0xB472360FFE1E02E5,  0x90C86A8B9F0AF04D,  0x22AD122520A264CC,  
		0x7737F589301E4255,  0xEA09EB3A667B43B3,  0xED6EA20BFD196FEC,  0x2ACA3D35C01F1E25,  0x5112A266D7EE12C7,  
		0xEDB9ADE3B424661C,  0xB20860BF200612BD,  0x04ECCF550669CBBB,  0xF6DE4179FD0CC810,  0xC594148B2667049B,  
		0x053EC9FAD230341C,  0x5A8005FCA0E89CCE,  0xC42D2A86C54D7365,  0x19561CA99616B100,  0xED1A9FEAD1927952,  
		0x931DB5F1C2513D6B,  0x476847D9AE56451F,  0xD5B9B479E7028370,  0xC9B40DC560F560CA,  0x99043EF7782DF811,  
		0x87539940A3A0EE07,  0x19B008D18C15C7A9,  0x78AC16D0AB429A81,  0x97B64E0C8C0D4F8F,  0x449AA45B0B9ADBEE,  
		0x1804900AF80B0C88,  0xE9EBCF37CAF59DC1,  0xA3408F3FDA487531,  0x13E4FF34EDE96581,  0x4FE6DAFC34CB99CE,  
		0xE62E53AFA7ADB00F,  0xFEA8400EA86D3F1D,  0x04F2B234F4CA395C,  0xD6DD2502FB67101F,  0xBFD004EBBBE05163,  
		0xD001C357E54A82F8,  0x4340DE592B97245E,  0xF69FEC1A86AD374D,  0x0E67BBE374ABC197,  0x18AF27DB1C9978CE,  
		0xE4B604C3BC66833E,  0xB95AAA083A68BED4,  0x8DA71BE77DC69323,  0x6046C24B08440A31,  0xE2D71C97CECEF35C,  
		0xD6D7D78FD93874A6,  0xD002D7852B967F09,  0x68A18BED8954B1A1,  0x8303342809C596DA,  0x8D1272C1630A362A,  
		0x0DA3AD3E155BEE0C,  0xF99166CDB27C4E2D,  0x5A386A711AA57FEB,  0xF6B1114F16351F80,  0xB01EB10A91896B25,  
		0xAAC0187B2E3C8F58,  0xB0E0BDE8834D176C,  0x59E857F6ED323D08,  0x337587B0A633F338,  0x8A357C5CEAB45D3F,  
		0xF325BD99116292B2,  0x6244FFFCD2F64323,  0x0CDF08E6DFA3D604,  0xD6063E91150760F9,  0x924DF99040B5CCA4,  
		0x7FDEC3B1E7EE9039,  0x1FD84D4BDF069C5A,  0x17A9A05ECE68913F,  0x93A09F9A2AC0960A,  0xBE731B0E91987CFC,  
		0xC1FC1D299344A78F,  0x47799736A4C5674E,  0x8152A14F454A5125,  0x7EE6C15BEEBA3EEC,  0x3624650AEDEDFE35,  
		0x16D72743790EA00A,  0x19FB10721229EC81,  0x85B1ACEB6A41611D,  0xDF524520064EFA06,  0x677AAA8B5D222D66,  
		0x130F0E9AC2271108,  0x28AFF1E046B71735,  0x33DEC074BCA34B22,  0x3E6945A213563C01,  0xCAE77D352CFC9758,  
		0xCEDD790A1C60EEBA,  0x817300F38F66047B,  0x19143AE839A27111,  0x2ECC0ACD207A9858,  0xAC7803CB23F3A28B,  
		0xEA48F53D74C4A58E,  0x431E7D5C8A69C486,  0x11890AABE8C8AD06,  0xAE09A61387F214AC,  0x7C33BD4BAA305554,  
		0x334BB3FEBCE49B68,  0xC70AD3C513C63193,  0x3CDB8F6956A63248,  0x99F06AE70C10C279,  0x6E16EEBD2F2C0682,  
		0xC18333F3D18E9FB3,  0xBF4FEC014EB9C5F2,  0x573E8AEBE795DCCD,  0x1470DDF9A3E1C943,  0x54953487341B542F,  
		0x7FA576E8E070FC2C,  0x90401C5F98A95BF9,  0x0D25ED973D7B8CE2,  0xCB09FD1FB002D3BD,  0x7BA0863E1D849E2B,  
		0x4CA22A556600C773,  0x3F6DF49CC12CE3C1,  0x738D31DC605EE312,  0x379F2A78F19E46DA,  0xA70E4DA2AD50F3B5,  
		0xCD211A668B700115,  0x50F1D9D72FCA8637,  0x079229C4DD6C961E,  0x8961CB65919CA8AA,  0x6317C2654032C8C4,  
		0xF27DEAF2E887BB19,  0x8860B0694E63A65A,  0x962EF558BDABE56A,  0x7E307F71209B9B8F,  0xE0BFC7F6CDBD8364,  
		0x8C321F42CD134833,  0xA00500F82C987528,  0x8B7DDFA8D0798372,  0xF36A6DFDBFDE1193,  0xA420914B5C214895,  
		0xA701BA76CA82C969,  0x521E71E4B549A449,  0x4CB97E308E25AD40,  0x69D3C134C1E4C4F7,  0x5D2808841F634D77,  
		0x0D39F5B5F8E294B5,  0xDEDE80D5373D22C3,  0x43838810D69FD1DC,  0x3A02C5DF95FD2717,  0xA4A856F899BF833F,  
		0x67F4CEAABAFDD1F8,  0x54E1BE0A1158779B,  0xCE0B65BF10EF9877,  0x4AC045F452E94BBC,  0x18FE7D967F50B061,  
		0x276D362D2D52C961,  0xFE5B48029FE7776B,  0x2DCD8D0D457E60F1,  0x74687DA12A33D26E,  0x4CAC5E41A22C9A75,  
		0x2924523A86F1EDDA,  0x13AFD5052DE12E78,  0xB8970343B2D85018,  0x64CF7BB3889695BC,  0xCB70B27C29EDF774,  
		0xAE2078CC0E7ED6E3,  0x02FB0C044BE718B6,  0x7C3B0E8C25AD3B7D,  0x18AC41058E1F50A7,  0x6E21B9E1DA39F220,  
		0xB02D9A63E8E30A0A,  0x4A7AB37A36F40967,  0xDC74A5B543DFCAD1,  0x451536470875301D,  0xB594961A00A95E9B,  
		0x551B6DEB38EED0D2,  0x4731B64C6A70B9B7,  0x99F9F0FD9CBC03AD,  0x790FCDA30F14C748,  0x50EE1335C25BFF43,  
		0x8DF5D284DFEDEE37,  0x71532E198C0EB9AB,  0x832CC61CF7BE441A,  0x8431DFD16E0E5D33,  0xCE26F2F74F5FF23B,  
		0x1E36D36389CAA05E,  0x9063D6730BE1105B,  0x8426CF9EAD688711,  0x9D6ECFCE2EEBF9EF,  0xDB03EE882634231D,  
		0xCDDC3ADC955B35E5,  0x0088C2423D74A486,  0xF673544C6028BE34,  0xA04131D948A27E35,  0xE638BDA968CF9BBE,  
		0xC771048BD8A021FA,  0xDAD72421848E3455,  0x3823689FAF46EF08,  0xDAEBE25DE0E823E2,  0x042187F1DF14F055,  
		0x4B02678EF80956F9,  0x453C53FBFE998478,  0x8E95702144B82C60,  0x833721170FB20F07,  0x8C32A35C83AC7459,  
		0xCAD051568A627384,  0x7CE5687A7B3E07AA,  0xFEC3F6664BAA644B,  0x9D54519E7A81B5B5,  0x4D55FB62A2619431,  
		0xC489E75B4E054027,  0x3CD217B9FEB7A7A9,  0x0321E049527F5402,  0xF99BA6AC4C9CEAAC,  0xAFA2B9809CE8BB0B,  
		0x82CE0815E5FBE2BC,  0xDC0DCA97EB94ADE6,  0x29168ABCF745E0AF,  0x5F3E461C04F38E68,  0xC859526F8F744C33,  
		0x0471B23F96E1B2E6,  0x51D918C90C459322,  0xA65E58D41C659E86,  0xBC0492880C19011A,  0x6B87CD75500557DF,  
		0x98B0F0F3F069D803,  0x0903890E45D25671,  0x4472AAD46E94E05B,  0x61AB4EC37A9108B4,  0xC3EE971E1827E088,  
		0xEBC32B8DFC648FD1,  0xA062D075D09D0C81,  0xC0603BAD959A4B46,  0xA5527848FC0C9B83,  0xE862CB609B417DFF,  
		0xE022C644B8F057BD,  0x54A4B726776C07AA,  0x69A4A18596C5BC07,  0x13FD171B42073056,  0xDAEA4FE81BEC1E2C,  
		0xCC0914D4435B2997,  0x9472D97736C7884B,  0x5B2DFF6798737FC8,  0x6A9C95FF10C8D257,  0x4D105A26EBB48F1F,  
		0xA676BD62CD9DD4CC,  0x40C7B3DF5320FBB2,  0xF0736459B5743FFD,  0x6B58E23B31D2F8A0,  0xF52472D206CDCFB7,  
		0xE38F1B3C3B6CA9F2,  0x7D117B425B09C90E,  0xD00D0990764D6DFA,  0x21E1EEC210678086,  0xA77FB3D15C772E37,  
		0xEE7CBCD634EDA0F9,  0xF71B168F0B4C4D03,  0x676423669F2B1FEA,  0x8718F95C5744AC99,  0x3E814F6EA487CA28,  
		0xF9B623DB5AFAF539,  0xBBB6B57918552BEA,  0xA9321D1E40017B6B,  0xE3FB9E19DB9AD9C9,  0x069EE17B941644B7,  
		0x0D694A1AAB075C4A,  0x4FD6ED4B4662F84E,  0x018AB024EF4245D0,  0xC0B3B1CD2EA45A6B,  0x9A674E454352DB2F,  
		0x1CAC78C74B291487,  0x742B80B29588413A,  0x5448D7487AC0D187,  0x16F5A8CCE0E2E601,  0x8F5CCC31E4C2EC92,  
		0x5C3A8F6727A2EA95,  0xBBC9F817CB92EA36,  0x035937EEFB453A92,  0xEA8C9543B50AFEF8,  0x235ED31EE2CBD0BE,  
		0xF4216C7AB05DD391,  0x06A58B753DD7F47E,  0xC3D6C97C5230565F,  0x19DC47B841BC91EB,  0x7969DCFB0DB20AD2,  
		0xCD339C65454D3ED2,  0x4B515D1EA4B33AE1,  0x0DCE3FEDE8C618EA,  0x2C65A573C8C103C9,  0x913FD343E8DBFDF2,  
		0x0F19A77D7C89BEA0,  0x46C9F43CFE8D3CA8,  0xE940A1E396CE0E8C,  0xAC30DDE2B90455B5,  0xB7696198FF61B997,  
		0x4868F7E06B61C5F6,  0x80177A1322C12E73,  0xE705C5C37DFD2FD3,  0x3FB2BC0BF20088B4,  0x363BCCD9593B1F88,  
		0x37C8910A5AD75645,  0xC86D48089FBDA682,  0xF94479483EC82424,  0x4BA48007EE523440,  0xDB8CAD5458763DAC,  
		0x27035FF601A5775D,  0xDBF789243B5760EF,  0x921906541C593FAA,  0xDBD7BF15F41DC3F0,  0x9E382502BBC86285,  
		0xF16292B70F4AF1C5,  0xB84D63E73E5694C9,  0x030038F0B77993E2,  0xDC5ECD77FBD69A0C,  0x7F16A9877E217B18,  
		0x14C6F6741F211F11,  0x6630E0B9BF94FD17,  0xB86316A4F7AAA58F,  0xFC643B05B63DCE6C,  0xA6560B91627721B5,  
		0x8320ECFD81283657,  0xB5A8C39DBB6E5E23,  0xE826B15B6706A0EC,  0xDCF97C212AB97924,  0xD313F455C110FD56,  
		0xF492138CFD67E673,  0x7B1A3887C029D13F,  0x3DA7F5CB3545E2CF,  0xD3A2C38E32DF47A3,  0xC62D0094C162C328,  
		0x3B3702CBDBFE909A,  0x2B832B8487700F2F,  0x4DCC5F984F8A78DE,  0x918B8840F5BAF78A,  0x2C965967F7078317,  
		0xC8F2762A261E8204,  0xBBCDA852563FD22F,  0x5140EE849404CA65,  0xE45F36A8B694AB45,  0x9B24FE28320004DF,  
		0x3642811B09588EF4,  0xD788DC4FEF59972F,  0x0A3A96442083B501,  0x227C1734A268AFE3,  0x290E5437196AE2BA,  
		0xEF952AACBA3F4F69,  0x6CCFB906C6257385,  0xF25E271738CBCCC9,  0x388BB6059078CC70,  0x7A855B726E341043,  
		0x55C948D0443B26C0,  0x4AF14082A6D39824,  0x8785DD062F4572D8,  0x2E8450859ED77085,  0xB1E139E09A1E5BE6,  
		0x6F3D0AFD812024E4,  0x3678D3AC8EC5FE3E,  0x468F22A9A2B46AAB,  0x7975967539FDFD49,  0x3A3560DC389AE61E,  
		0x6C99F906B7B4A36E,  0x2963C8E15BAB0750,  0xCE24F1B554416568,  0x2D2DBC483475230A,  0x73281531024053E0,  
		0x7617116008FDABCD,  0x49F30EF0400C0946,  0x9A323C5AC6C1594E,  0x7384B69C2FE14737,  0x3CD39D0AACF4B123,  
		0x1474DA2902DF8DFD,  0xD4CB5B4555ABD17C,  0x4093DD219148D1EA,  0x523FFE88F02E2717,  0x9A859EF4595B5D94,  
		0xFBA7DE89B355E9D7,  0xCBE4A7E7EA74BD42,  0xB40DADE54C85679D,  0x3D02FAA4C31F0F0E,  0x45AF5A43FE4FDB5B,  
		0x5F22CB1966E21485,  0x8D2F71C0299D5E78,  0xC311B6C8F3CFB5C5,  0x54FCF08384B17CFC,  0xBA4D4267CFDC1B71,  
		0x80372F0E350AA920,  0xE46A08F72B35EBF6,  0x8A4185B3C3D5C92F,  0x9F38656156F1E1ED,  0x065D806B601DF2E5,  
		0x382C64EAD6812C9E,  0xDB0EB3157EB4A9A8,  0xBAD5F2966684A8FC,  0x99AF45FACD4BB152,  0x6CBD9DF2BCABD086,  
		0xE588904644DD4D64,  0x24C4D68E4A7E0CF3,  0xD8E4EED8973A24D5,  0xB52B64AB97F9C29A,  0x0400DCDCA40D8CE7,  
		0x95AAA38C231EA8EC,  0x2B5FED1A3B68C19E,  0xF0993E0F9E9C3F7F,  0xFAF9230D5E7020C7,  0x8CD41F2333F1277B,  
		0x73D2955F527964C5,  0x283480D1DC743465,  0x940DBC679F722E6B,  0x759C7A9D40DC74A0,  0xC80D7AF3E01CF9B0,  
		0x4831360B9FF3911B,  0x8047119C09416F0E,  0x451F5B2ECB5504FE,  0x7C76297FE49AF3B5,  0xD04E4A395C1EA162,  
		0x5455DE5654E27508,  0x80B026FC61B1664C,  0x39A66D48F9FCBFFC,  0x10624B8841B04184,  0xB93412265EEDD34E,  
		0x659BDBEE52978D0A,  0xBAB1CB0366D793A9,  0x3D6FC272F1588226,  0x93B07778DAE82B37,  0x52AFA557F6939375,  
		0x7A94983330B73A38,  0x93C1C1AD49228F5B,  0xCD6099A1073D6482,  0xFC0B756AA1C7DDBD,  0x5F4A151C1824C829,  
		0x02909A63AEF3EEFB,  0xC17B52F0DBD89397,  0xA9B8F77BEFBC5776,  0xC90B5944C85555DD,  0x05AD91C65A2DEA33,  
		0x581B9BE28D61520B,  0x798CA01A3B55BE4E,  0xC435D385A46FA6C1,  0x39B884E6FE73365E,  0x826A84511F118D67,  
		0x94CE8FF134E42DFE,  0xA4594EAA7C79E0AB,  0x2F5BB7E4D9863113,  0x22328FC1DD34102A,  0x922A4E802855E184,  
		0xA6EEDBA3D3DFB782,  0x0A103D6B864CC380,  0xDF591DBCFA3BC90E,  0x7467D19DE5885D90,  0xD437324803A0B122,  
		0xAEEAF37ED6F1C0F8,  0x65C19736A87C9488,  0x2E6BD6CD9CBC783D,  0xDCC129A42217657F,  0xFFF0A2971827D4C9,  
		0xEE17CA08AA888C93,  0xAD004364A1267202,  0x5A1858DC3A625F09,  0xC872BC0FBF8A5350,  0x4C02CB7A7428A2AF,  
		0x6EE5107F63A013E8,  0x611B619D3D71FF50,  0xA6F364E2A71E0250,  0x343EAADA15F58825,  0x2BA817C5977D86FE,  
		0x7C7AB51D36AE0BEA,  0xC912A9B717F8AC80,  0x751F6D26CD92A88E,  0xA1C66600137B590B,  0xDDDE94ADAE44C793,  
		0x3602893CC5FB9465,  0x53FBBAC7F4883A94,  0xDC93E87D60D1E284,  0xBC365EDA830FBB94,  0x5C0331DABEBA9A60,  
		0xB9FED85727BD2AF9,  0xBA6CBA470A6781BE,  0xBDAE4A1DE6209566,  0xCD685FA9ED7D2A07,  0x52E3B379219165D6,  
		0x03ACE6265E255F65,  0xD3CE5E1DC1EBBC98,  0x31A4F7C4765F42B9,  0x1816FCC720964226,  0x5AF18278F263302E,  
		0xE8408C7FB70F04EF,  0xE6E00DE18A92AF6E,  0x5AC1D7C694EA9384,  0x5720BBD6E17F27CA,  0xC0BFDA4838C0A0CD,  
		0x8891314377C5C1CE,  0xF73C59F42E342631,  0xDFBA9386CD8C911B,  0x88AE1ACCF2D3B7D4,  0x37A50DF2549E2483,  
		0xD467C1DA0438A95A,  0x7BF166C31E273FAB,  0xD6D2CD348367C5CC,  0xB8A9DF4BCC6118D0,  0xE971BF3BF4194B99,  
		0x8D0A43CF4A654E5B,  0x0DC1DD89322CA5C3,  0xC48380DEABB23363,  0x8C7DD54DAC2A0DBA,  0x8485A1DC20E7DF58,  
		0x9D699A56EF536D74,  0x4028FA9730766C68,  0xA4B8CFFD806F8FC0,  0x2E8FA0BDA00FD155,  0x04497FE00411FCEB,  
		0xB7E7D53DBED496DF,  0x4252B54D01B6DC29,  0xC138A56F904C9DF4,  0xA6D0C9DBFED0E668,  0x22B15442FD5B1331,  
		0x66E16BB9B14E756F,  0x88F5F86AB2915586,  0x6B650CC7C4F41281,  0x99EEE1DCBA3DD0FF,  0x60AB7EB50B6129D1,  
		0xB2E9FAC8B4E3EBF5,  0x219007C91446448C,  0x5A5E6A72DBB9743B,  0x5359FA3041F37150,  0xED75173B3F10CAFF,  
		0x32D7101DDE00633C,  0x1A76945CFD96317A,  0x3093C632E27659FD,  0x3F8DC3CEC97D5DA6,  0x53B8E71D8575298B,  
		0x4AD3D0EEFDCAB589,  0x2AFF9B8400084673,  0xAF617981D01788E4,  0xF354BBCA2C5BA3D9,  0x4D2C93D55A3A2C3F,  
		0x862E1A64DC4B02A0,  0x48BCB6A7536B45A4,  0xA037E8F116B81D54,  0x864DCDC4219BBA94,  0x8DED7C57E8E072CA,  
		0x6BBBF11E39D0CFEF,  0x30D570DC9066E198,  0x379F777159777FF0,  0x3782E9FB1B80E0CF,  0x2443ED5402C19F64,  
		0xE623C7945E447698,  0x04B129E49B4AF2C6,  0xB74DCDEFEEB92BAC,  0x22C21F1C5E491CEC,  0xD6E38CAE64FA32BD,  
		0x814E5111CACC2C62,  0x8D518DD58941DD42,  0x66B50953DA96C9AC,  0x1A0DC5B10F67D34E,  0xBC9B35C7E74977FF,  
		0xD328E25125F9EA56,  0x037D6155F9B04B3B,  0x0EEB5A021EAAF710,  0xE5B8ABEC5A2BB91E,  0xDDDFB7263681A0D7,  
		0xDFF62B4261429115,  0x7951E16A2DCB212F,  0x1E718209C4997D14,  0xAE35CC615A738865,  0x7954D41176968751,  
		0x108C0622D305A85E,  0x486E9F2BAE384BE3,  0xE1C9618F653F390F,  0x89D21E79189F0A90,  0x87666B7B28B2B63A,  
		0xA172AC0B970F0C4B,  0xDFA9E4078CA26C5D,  0x0B9AA7A20A2F9136,  0xBBE75A0527D33AF5,  0xDB20748F0E880F21,  
		0x92D1A944B9C2CC8F,  0xA887D8AD7E48BDDE,  0x052C22591E39F932,  0x42C55E93519195E1,  0x8D092E4C56EA4625,  
		0xCF1ECA0858904F08,  0xBDF11765EA550E2B,  0x35AF430B91E2E880,  0x34B1652A53DEDFA0,  0xDD5AED9253DD2016,  
		0x023E515186981A1B,  0x2688866C6859CE84,  0x07F609787ADBDB88,  0xC9BCC491A0EF2F77,  0x5EBFF9EB8E86ECD8,  
		0x003CBD6A94817F57,  0x27E864F6502F28AF,  0xEB23B677EF3CDE22,  0xB842F3ABC75E5AC0,  0x8AE45B06CB315DD9,  
		0xE6019D35966FE4B6,  0x77ED4D7871E65C47,  0xD9DCFC45565E9DD8,  0x3F3A94EB36501335,  0x168CF34F315A74CE,  
		0xCCDEADEB12C8F742,  0x903A3BC72EB6E730,  0x0D18DB17A7B55CF7,  0x027B0EAF0149F8C1,  0x7454ED83E5AFBCD2,  
		0xF093C14BE10B848A,  0x117B8FE0612BA25C,  0xFB1BBBEBF1511C32,  0xDE3D3F558DA62788,  0x81CEFE3C56A63E3C,  
		0x808EDD39739424E9,  0x6A4098B0D1F68A21,  0xC15559A8A6694883,  0x8642811FE238D154,  0x2042B4535724E040,  
		0x0147D5B5BA8D06B3,  0x9634AA9E63FAA25B,  0x6CA680FD704C29FB,  0x17E7B48ABECE6D30,  0x518E67C80B2DF330,  
		0x849C20A7FA51A95B,  0xB6A9BA4C0148C21C,  0xF15346A188BC7C0D,  0xB0CAF0E54952C04E,  0xC38F5BC97F2E1CF5,  
		0x9BB0CE74F7214846,  0x100CE94FCDF6BA3F,  0x83CFDA62B11092AF,  0x24B3ECB0580A2E70,  0xD63C66E3609A72D0,  
		0xBB019C1DF325B71E,  0xA235892634F09DA6,  0x8B7BB697A62B28E4,  0x72780CA6CC37A33D,  0x3D4105927C719BFE,  
		0x9D6DE4EFC66AF83F,  0x4893B8FD02D58E69,  0x9C7035A28CC43DDF,  0x7A4201AF8686CB87,  0xDDBE1BB320FF707F,  
		0x2A1D3626FD9D5E8C,  0xE471184FF97CD9C0,  0x2A2ED5C026B5BC48,  0xCFA0D9FF71F120E9,  0xC92E7B76EED97A04,  
		0xD80D270E93D92CBE,  0xCAB996739436A28C,  0x7411C178D6A0CC42,  0x051B2091D03357A3,  0xD64B4405DCF7D7F6,  
		0x18F95D4C5C8B3D6D,  0x5E3F16624B834396,  0xF5046252ED5BFE90,  0xAD7DCE9584A4F865,  0x50CDDA5B84FFDB27,  
		0xF1246D3505C0DA7C,  0x1031EE90DEDC79B4,  0x99409B577C081FCA,  0x664C7F4F1B4D68B0,  0xD78D714AD16A2D97,  
		0x15B1E5B3A106B873,  0x8F1F77AF15EC99CF,  0x25B4B0CE175CA086,  0x09002D966E563F5F,  0x53C20718B90A909D,  
		0x906509ECBEAA2168,  0xAE6C7B25D0282CC9,  0x260F906C0599AF1F,  0xE77FAD487A24D5A5,  0x0F914EFB75B0EA7D,  
		0x7584B746E5BBD08B,  0xAE95D35C31A18E3F,  0x1560AEFB1CF2B912,  0xAFF7A6A5D2B223C5,  0xB4461D12225A6C64,  
		0x3C572019F2EE97C4,  0x42F349EDBAE36833,  0x0E05CF63C06AD4F3,  0xAF450FF674BC724A,  0xF48C5B768B6D4E16,  
		0xC2678C86DFCA1B17,  0xC6B1C2BD370E3D15,  0xAA7E82DB85741CA1,  0x8AD4EF691A70C302,  0x685EA34C839108BD,  
		0xBC91533A604E9539,  0x96FD0062496FFC8F,  0x7811BD27B34C8E00,  0x5C849F285E09F489,  0x31173CE56F085B52,  
		0xEE83D46E93993392,  0x8FA7B0500890B4B7,  0xBD70197C26DFC8F9,  0x607AE95A948A095B,  0x19C4A4058799EC55,  
		0xC5A9FC21E5DF09C0,  0xB84AAB0833AB7396,  0x76C6586A1D825CBB,  0xF59BF07BAFBCE6C0,  0x006CDBC5D26A45A8,  
		0xDCC25A9F0621F62D,  0xCC8C4E48A08511EA,  0x83D4B2EF97F02B4F,  0xF7FFDEA8960C5E39,  0x2DC0D8AC3C6A6140,  
		0x41C7B8500839B853,  0xBBF5CD196FE639A6,  0x3E1079E27B02DFFB,  0xA76CEC86758C2BB9,  0xB5616951A3210279,  
		0x4895FC655659C663,  0x10B487B086474DF6,  0x5AF2A8975C049BDE,  0xBFDEFE754304B65E,  0x45B88C628F6DDC35,  
		0x529CEDFE80894BBB,  0x7893CA4F2876B58B,  0x4FB8EDAC55FAA221,  0x2CB1F57FC830F42B,  0xAB2FD4FF09CB15A3,  
		0xF8807AE98E7BE19B,  0xFDD9CEB0831438E7,  0x02140517E93E594E,  0xF90B46D491978B57,  0x8AF75603E59942A8,  
		0xF8C3FF97B4A6BBFE,  0x0222DBCE5A80EB73,  0x696FC14AADDF5091,  0x002EAB000050EAF6,  0x9CE095F19A33943D,  
		0x80509F3E3A14154B,  0xEF12F29F6A70C823,  0x90845E3B835067AA,  0x58761D7BCBF5BFAF,  0x3642EBF4684689BD,  
		0x3AD94A5B0B136D36,  0xE5769F142EC75540,  0x41C63560DA077771,  0xA6DEC4BF6ABD9C76,  0x30F9B73ADA41CED5,  
		0x8BE437BB6BD7F13C,  0x4DD52D0A7130F1DA,  0x21DD6C4A48B349BF,  0x4D075B28BE81B1AB,  0x2015ABDD10265D21,  
		0x2E57D1809F4E64DA,  0x7C68260B225BC190,  0x4F642E4470619C09,  0x9C0CEB14698F06A0,  0xF549EC5D615C2CA5,  
		0x9B3DAB7E656689E4,  0x169BD9FD0B0F502C,  0x789E4C2EC3F5E913,  0x54AD454B45213A92,  0x52DE32B560A08C4C,  
		0xAF256539D19378BE,  0x19D0D644BB379C2A,  0xB8EF87180876303E,  0x7A3FD33298B522C7,  0x5C0EDA92E2AA0B9B,  
		0xE706EC9A4B3F63E5,  0x74793954C032CAF6,  0xE48B4617201177D1,  0x230EA19A354026D7,  0xB76EC257F03435C3,  
		0x3AE38F8730B58355,  0x0E606E9ED3E4CDBB,  0xEE7F1435578A6BFE,  0xC33ACB0D48CEE739,  0x22581EEA220F8529,  
		0xF32247EE8044013C,  0xCFBFE9054ABE9D9B,  0x62222D068CC9F967,  0x5995FBBF99CD639C,  0xC6CC45300D6C5B46,  
		0x1481DBE1357202FC,  0xB7A96A728972B607,  0x99214F30845F2D92,  0xA8CE40FF3821861C,  0xE977CD5CC68E5635,  
		0x45B2E656365F11A6,  0x2E1946BFB828464E,  0x6C712927B73539A1,  0x4CF2A263C2EE4064,  0x55D73A52543B8718,  
		0xD536CE475C222659,  0x5B4323B0D024F2F4,  0x2BE31CE217972835,  0xD2056238A7BE6027,  0x2472B58E5C2C68A5,  
		0xEE0CFA3C3CDBCB3A,  0x2BC3D67C2A9456A6,  0xCCEC927102BA9F8B,  0x99D4D26634F2C7EE,  0x90CD28B0A49941BC,  
		0x4BED3658846DB60D,  0xA2AABE2DED518020,  0xEDE9C05C8179F062,  0x7E3E3C3949ED0D33
	};

	void Position::gen_moves(Move_List& list)const
	{
		int from, to;
		int me = turn;
		int opp = color_opp(me);

		list.clear();

		BITBOARD piecebb, movesbb, target = ~piece_block(me) & board_mask();

		from = king(me);
		U64 movebit = king_attack_bb(from)[me] & target[me];

		while (movebit)
		{
			to = pop_1st_sq(movebit, me);
			list.add(move_make(from, to));
		}

		piecebb = pieces[piece_make(me, Advisor)];
		while (piecebb)
		{
			from = piecebb.pop_1st_sq();
			movebit = advisor_attack_bb(from)[me] & target[me];
			while (movebit)
			{
				to = pop_1st_sq(movebit, me);
				list.add(move_make(from, to));
			}
		}

		piecebb = pieces[piece_make(me, Bishop)];
		while (piecebb)
		{
			from = piecebb.pop_1st_sq();
			movebit = bishop_attack_bb(from, blockers)[me] & target[me];
			while (movebit)
			{
				to = pop_1st_sq(movebit, me);
				list.add(move_make(from, to));
			}
		}

		piecebb = pieces[piece_make(me, Knight)];
		while (piecebb)
		{
			from = piecebb.pop_1st_sq();
			movesbb = knight_attack_bb(from, blockers) & target;
			while (movesbb[White])
			{
				to = lsb(movesbb[White]) - 19;
				list.add(move_make(from, to));
				movesbb[White] &= movesbb[White] - 1;
			}
			while (movesbb[Black])
			{
				to = lsb(movesbb[Black]) + 45;
				list.add(move_make(from, to));
				movesbb[Black] &= movesbb[Black] - 1;
			}
		}
		piecebb = pieces[piece_make(me, Rook)];
		while (piecebb)
		{
			from = piecebb.pop_1st_sq();
			movesbb = rook_attack_bb(from, blockers) & target;
			while (movesbb[White])
			{
				to = lsb(movesbb[White]) - 19;
				list.add(move_make(from, to));
				movesbb[White] &= movesbb[White] - 1;
			}
			while (movesbb[Black])
			{
				to = lsb(movesbb[Black]) + 45;
				list.add(move_make(from, to));
				movesbb[Black] &= movesbb[Black] - 1;
			}
		}
		piecebb = pieces[piece_make(me, Cannon)];
		while (piecebb)
		{
			from = piecebb.pop_1st_sq();
			movesbb = (rook_attack_bb(from, blockers) & ~blockers) | (cannon_attack_bb(from, blockers) & piece_block(opp));
			while (movesbb[White])
			{
				to = lsb(movesbb[White]) - 19;
				list.add(move_make(from, to));
				movesbb[White] &= movesbb[White] - 1;
			}
			while (movesbb[Black])
			{
				to = lsb(movesbb[Black]) + 45;
				list.add(move_make(from, to));
				movesbb[Black] &= movesbb[Black] - 1;
			}
		}

		if (pieces[piece_make(me, Pawn)])
		{
			BITBOARD piecebb = pieces[piece_make(me, Pawn)];
			if (me == White)
			{
				movesbb = (piecebb << 9) & target;
				while (movesbb[White])
				{
					to = lsb(movesbb[White]) - 19;
					list.add(move_make(to - 9, to));
					movesbb[White] &= movesbb[White] - 1;
				}
				while (movesbb[Black])
				{
					to = lsb(movesbb[Black]) + 45;
					list.add(move_make(to - 9, to));
					movesbb[Black] &= movesbb[Black] - 1;
				}
			}
			else
			{
				movesbb = (piecebb >> 9) & target;
				while (movesbb[White])
				{
					to = lsb(movesbb[White]) - 19;
					list.add(move_make(to + 9, to));
					movesbb[White] &= movesbb[White] - 1;
				}
				while (movesbb[Black])
				{
					to = lsb(movesbb[Black]) + 45;
					list.add(move_make(to + 9, to));
					movesbb[Black] &= movesbb[Black] - 1;
				}
			}
			if (piecebb[opp])
			{
				movebit = (piecebb[opp] << 1) & ~file_mask(File_A)[opp] & target[opp];
				while (movebit)
				{
					to = pop_1st_sq(movebit, opp);
					list.add(move_make(to - 1, to));
				}
				movebit = (piecebb[opp] >> 1) & ~file_mask(File_I)[opp] & target[opp];
				while (movebit)
				{
					to = pop_1st_sq(movebit, opp);
					list.add(move_make(to + 1, to));
				}
			}
		}
	}

	void Position::gen_legals(Move_List& list)const
	{
		int pos = 0;
		int move;

		list.clear();
		gen_moves(list);

		for (int i = 0; i < list.size(); ++i)
		{
			move = list.move(i);
			if (move_is_legal(move))
			{
				list.moves[pos++] = move;
			}
		}
		list.cnt = pos;
	}
