// /clone/board/wuguan_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("����������԰�", ({ "board" }) );
	set("location", "/d/wuguan/wg_dating");
	set("board_id", "wuguan_b");
	set("long", "����һ������ݵ��ӽ��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

