//Room: /d/dali/cangshanzhong.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��ɽ�в�");
	set("long",@LONG
�������ڲ�ɽ�в�ɽ�ߣ��˼���μ��գ�����ɽ�����ƣ��м�һ
����᫲�ƽ��ɽ·��·����Զһ������Ա���ƫ��������������¡¡
ˮ��ңң���ţ�������گ����--��ˮ����·��������������������
�ؾ�֮;��ʱ�п��̹������ɴ����ϴ�Խ��ɽ�ɵ��¹سǣ����治Զ
���ǳ���ɽ��ɽ�ڡ�
LONG);
	set("outdoors", "dalin");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"jianchuan",
	    "southwest"  : __DIR__"cangshanlu1",
	    "southeast"  : __DIR__"xiaguan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -89970);
	set("coor/y", -69950);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}