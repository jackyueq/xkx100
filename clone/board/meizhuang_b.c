// /clone/board/meizhuang_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�������÷ׯ���°�", ({ "board" }) );
	set("location", "/d/meizhuang/dating");
	set("board_id", "meizhuang_b");
	set("long", "����һ��ר��������̽�����÷ׯʹ�õ����԰塣\n" );
	setup();
	set("capacity", 300);
	replace_program(BULLETIN_BOARD);
}

