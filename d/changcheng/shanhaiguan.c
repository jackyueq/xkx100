// Room: /d/changcheng/shanhaiguan.c
// Last Modified by Winder on Aug. 25 2000
#include <ansi.h>

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "ɽ���س�¥");
	set("long", WHT@LONG
�����ɽ���س�¥������Ρ��Ľ�ɽ��������ɽ���ϱ��ڣ�������
ʧ����ɫ��Ⱥɽ֮�С����£�����һ�ߴ��ϱ������棬�̲����꣬����
���ġ�����Ԫ˧����Դ˴�����ɽ�󺣣�ʵ�ɼ��ʺ��������˹ء�
LONG
NOR  );
	set("outdoors", "changcheng");
	set("exits", ([
		"northwest" :__DIR__"changcheng23",
		"down"      :"/d/guanwai/shanhaiguan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 5000);
	set("coor/y", 5000);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}