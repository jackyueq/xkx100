// /clone/board/gaibang_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("ؤ��������԰�", ({ "board" }) );
	set("location", "/d/yueyang/gaibangtang");
	set("board_id", "gaibang_b");
	set("long", "����һ����ؤ����ӽ��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

