// Room: /d/changcheng/changcheng19.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", WHT @LONG
�㳪�ţ����ţ���Ȼӭ�����һ���磬��������ͷ������������
��ɳ�ӡ���ļ�æ�������죬����һ��ȫû�ˡ��㿴��һ����Χ��ֻ��
�����Ѿ����ٿ���ֲ������ǻ�ɳ��ʹ�˸е�һƬ������
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"southwest" :__DIR__"changcheng20",
		"northeast" :__DIR__"changcheng18",
	]));
	set("no_clean_up", 0);
	set("coor/x", -15000);
	set("coor/y", 10000);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}