// Room: /d/xingxiu/xinglongshan.c
// Last Modified by winder on Apr. 25 2001
inherit ROOM;

void create()
{
	set("short", "��¡ɽ");
	set("long", @LONG
��ɽ��������ɽ���ϣ���Ȼ���ܲ�������ɼ���ɡ��롢���������
ľ����ľ�ԡ����͵��䣬�ļ����ࡣ����̫�ס���ҺȪ�����СϪɽ����
�������������д�Ͽ�ӣ��峺���ף��ϱ���ԽϿ�ȡ�������ʪ�����½�
�ͣ�Ϊ��������ʤ�ء�
LONG);
	set("outdoors", "silu");
	set("exits", ([
		"northdown" : __DIR__"shimen",
	]));
	set("objects", ([
		__DIR__"npc/yang" : 2,
	]));
	set("coor/x", -22000);
	set("coor/y", 500);
	set("coor/z", 100);
	setup();
}
#include "/d/xingxiu/job2.h";
