// /clone/board/wuliang_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�����������԰�", ({ "board" }) );
	set("location", "/d/wuliang/road1");
	set("board_id", "wuliang_b");
	set("long", "����һ�������������½��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

