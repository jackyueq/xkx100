//Room: majiu.c ���
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","���");
      set("long",@LONG
���ǹ������ǣ�����ຮ֮�أ��ķ����ʲ��ϡ��������󺺹���
�Կ࣬����ǻ����ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�ø�
Ǭ������һֱ�ź򵽿�����·�����ѩ���µ�ľ��������ض���һ����
ľ��(paizi)��
LONG);
      set("outdoors", "guanwai");
      set("no_fight", "1");
      set("no_beg", "1");
      set("objects", ([
	    "/d/city/npc/zaohongma": 1,
	    "/d/city/npc/huangbiaoma": 1,
	    "/d/city/npc/ziliuma": 1,
		"/clone/misc/mafu": 1,
      ]));
      set("item_desc", ([
          "paizi": @TEXT
������ֻҪ�����һ�����������Ϳ��Թ͵�һƥ���ˡ�

ǰ��      ������:  ridebj


TEXT]));
      set("exits",([ /* sizeof() == 1 */
          "east"      : __DIR__"jishi",
      ]));
      set("no_clean_up", 0);
	set("coor/x", 6030);
	set("coor/y", 5210);
	set("coor/z", 0);
	setup();
      replace_program(ROOM);
}
