// /clone/board/yideng_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("һ�ƴ�ʦ���µ������԰�", ({ "board" }) );
	set("location", "/d/heizhao/chanyuan");
	set("board_id", "yideng_b");
	set("long", "����һ����һ�ƴ�ʦ���µ��ӽ��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

