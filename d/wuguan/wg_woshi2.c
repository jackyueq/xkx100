// wg_woshi2.c

inherit ROOM;

void create()
{
	set("short","��Ϣ��");
	set("long", @LONG
����������ڵ���Ϣ�ң������е��ɣ����Ǵ�ɨ�ķǳ��ɾ���һ
�Ŵ��̿�ǽ���ţ������ĵ��߹�ȥ���Ҹ�����˯��������
LONG);
	set("exits", ([
		"north" : __DIR__"wg_woshi1",
	]));
	set("no_clean_up", 0);
	set("no_fight",1);
	set("no_get",1);
	set("no_steal",1);
	set("no_get_from",1);
	set("sleep_room", 1);
	set("coor/x", 61);
	set("coor/y", -70);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
