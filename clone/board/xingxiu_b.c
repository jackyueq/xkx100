// /clone/board/xingxiu_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�����ɵ������԰�",({"board"}));
	set("location", "/d/xingxiu/riyuedong1");
	set("board_id", "xingxiu_b");
	set("long", "���ǹ������������Եİ���.\n");
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

