// /clone/board/bug_b.c
inherit BULLETIN_BOARD;
void create()
{
	set_name("bug�����", ({ "board" }) );
	set("location", "/d/wizard/bug_room");
	set("board_id", "bug_b");
	set("long", "����һ��ר����ʦ������Ҿٱ�bug�����԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}