// /clone/board/kunlun_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���ص������԰�", ({ "board" }) );
	set("location", "/d/kunlun/qianting");
	set("board_id", "kunlun_b");
	set("long", "����һ�����������½��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

