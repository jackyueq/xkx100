// /clone/board/kedian8_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�͵����԰�", ({ "board" }) );
	set("location", "/d/wuxi/kedian");
	set("board_id", "kedian8_b");
	set("long", "�����õĻ���������˵���ҹ�ˮɱ���⡣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

