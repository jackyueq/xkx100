// shishi5.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "����ʯ��");
	set("long", @LONG
�����ǵ���ʯ�ҵ�������һ���ˣ������Ǻں�����˵�����������
����������ŵ�ǿ�ҵĸ��õĶ�������������ζ���������ǿ���뿪��
�Ϻá�
LONG );
	set("exits", ([
		"up" : __DIR__"shishi4",
	]));
	set("objects",([
//		CLASS_D("xiaoyao")+"/xiaoyaozi" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -50010);
	set("coor/y", -21030);
	set("coor/z", -60);
	setup();
	replace_program(ROOM);
}
