// Room: /d/changcheng/beisilou.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", WHT@LONG
���ϱ���¥��ĿԶ�����������Ǵ��������ɽ���������Ѷ�����ç
ç�Բԣ���ب���⣬������ͻȻ�������棬�����ٶ����ƶ�ȥ��ǡ��һ
���޴����������֪��������Ҳ��֪����ȥ��
LONG
NOR  );
	set("outdoors", "changcheng");
	set("exits", ([
		"southwest" :__DIR__"badaling",
		"southup"   :__DIR__"nansilou",
	]));
	set("no_clean_up", 0);
	set("coor/x", 2000);
	set("coor/y", 6000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}