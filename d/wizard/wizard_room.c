// Room: /d/wizard/wizard_room.c
// Last modified by winder 2002/10/18

inherit ROOM;

void create()
{
	set("short", "��ʦ��Ϣ��");
	set("long", @LONG
������ǡ�������һ�١���ʦ����Ϣ���ڣ��շ�ˢ��������ǽ����
��ͺͺ��ʲô��û�У����ӵ����������һ���ľ�����������һ����
ʦ���Բ�(board)��
LONG );

	set("exits", ([ /* sizeof() == 1 */
		"up"    : __DIR__"meeting_room",
	 	"down"  : __DIR__"guest_room",
	]));
	set("no_fight", "1");
	set("no_clean_up", 0);
	set("coor/x",-1);
	set("coor/y",1);
	set("coor/z",10);
	setup();

	call_other("/clone/board/wiz_b", "???");
	replace_program(ROOM);
}
