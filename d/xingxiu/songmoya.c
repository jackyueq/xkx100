// Room: /d/xingxiu/songmoya.c
// Last Modified by winder on Apr. 25 2001
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIM"��Ħ��"NOR);
	set("long", @LONG
��Ħ����������������Χɽ�ƶ��ͣ���ɽ���ţ�һ����������Ͽ��
��̶��Ԩ��Ī�⡣�״��л�����̶�ɳ�����������̶��̶���Ħ�³ɱ���
�����漣���ʴ��پ������������������˿��쾮���Ĺ��̡��������ǳ�
��ɽ����������ʯ�š�
LONG);
	set("outdoors", "silu");
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown" : __DIR__"silk2",
		"westdown" : __DIR__"silk3",
	]));
	set("coor/x", -21000);
	set("coor/y", 600);
	set("coor/z", 100);
	setup();
}
#include "/d/xingxiu/job2.h";

