// /clone/board/wizcode_b.c
inherit BULLETIN_BOARD;
void create()
{
	set_name("����������Բ�", ({ "board" }) );
	set("location", "/d/wizard/meeting_room");
	set("board_id", "wizcode_b");
	set("long", "����һ��ר����ʦ��¼���������������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}