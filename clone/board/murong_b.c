// /clone/board/murong_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("Ľ�����ҵ������԰�", ({ "board" }) );
	set("location", "/d/yanziwu/lanyue");
	set("board_id", "murong_b");
	set("long", "����һ����Ľ���������½��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

