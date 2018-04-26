enum class PieceType
{
	King = 1,
	Queen,
	Rook = 10,
	Pawn
};

int main()
{
	PieceType piece = PieceType::King;

	if (piece == PieceType::King)
	{
		/* ... */
	}

	return 0;
}
