// Room: /d/changcheng/changcheng21.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", WHT@LONG
���ڳ����ܵ���ɳ����ʴ�����ٳ�ǽ�Ѿ�������ǽ�ǵĻ�ɳ������
��ӳ�ǽ�ϵ���������ש��ǰ�治Զ�����ǳ��ǵ��յ㩤�������ء���
������������ͨ�����ڵıؾ�֮·��������Ҳ����������ֻ��������
�𷢵����˴������ǵ��̶ӴҴ�����ȥ��
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"southwest" : __DIR__"jiayuguan",
		"east"	    : __DIR__"changcheng20",
	]));
	set("no_clean_up", 0);
	set("coor/x", -17000);
	set("coor/y", 9000);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}