// Last Modified by Winder on May. 21 2001
// /clone/board/nshaolin_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�����ֵ������԰�", ({ "board" }) );
	set("location", "/d/nanshaolin/pingtai");
	set("board_id", "nshaolin_b");
	set("long", "����һ���������ֵ��ӽ��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
