// /clone/board/kedian11_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�͵����԰�", ({ "board" }) );
	set("location", "/d/lanzhou/kedian");
	set("board_id", "kedian11_b");
	set("long", "�����õĻ���������˵���ҹ�ˮɱ���⡣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

