// /clone/board/kedian12_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�͵����԰�", ({ "board" }) );
	set("location", "/d/lingzhou/chema");
	set("board_id", "kedian12_b");
	set("long", "�����õĻ���������˵���ҹ�ˮɱ���⡣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

