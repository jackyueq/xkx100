// /clone/board/wudu_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�嶾�̵������԰�", ({ "board" }) );
	set("location", "/d/wudujiao/dating");
	set("board_id", "wudu_b");
	set("long", "����һ�����嶾�̵��ӽ��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

