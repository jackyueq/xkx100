// Room: /d/pk/turen3.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", MAG "������" NOR);
	set("long", @LONG
������ǻ�ɽ�����¶��ϵ��������ˣ�������ȥ����
�ܵĴ���£����һ�������У��������ɣ������У����
��������ᣢֻ�ڴ�ɽ�У����֪���������ÿ���
��ɽ�۽������ڴ������о��С�
LONG
	);
	set("no_quit",1);
	set("bwdhpk",1);
	set("no_sleep_room",1);
	setup();
}
void init()
{
  object me = this_object();
  me->set("exits/east",__DIR__"turen"+random(7));
  me->set("exits/west",__DIR__"turen"+random(10));
  me->set("exits/south",__DIR__"turen"+random(6));
  me->set("exits/southeast",__DIR__"turen1"+random(3));
}