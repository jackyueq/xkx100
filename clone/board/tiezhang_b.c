// tiezhang_b.c
// Last Modified by winder on Nov. 15 2000

inherit BULLETIN_BOARD;

void create()
{
	set_name("���ư�������԰�", ({ "board" }) );
	set("location", "/d/tiezhang/guangchang");
	set("board_id", "tiezhang_b");
	set("long", "����һ��ר���ڵ��ӽ���ʹ�õ����԰塣\n" );
	setup();
	set("capacity", 60);
	replace_program(BULLETIN_BOARD);
}

