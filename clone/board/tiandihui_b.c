// /clone/board/taindihui_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("��ػ�������԰�", ({ "board" }) );
	set("location", "/d/beijing/dating");
	set("board_id", "tiandi_b");
	set("long", "����һ������ػ���ӽ��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
