//Room: xiaolu1.c С·
//Date: Oct.2.1997 by That

inherit ROOM;

void create()
{
      set("short", "С·");
      set("long", @LONG
�����Ĵ�������Ľ��硣һ�������ĵ�С��·�����������������ũ���
���·�����˺��٣����ҴҸ�·��
LONG);
      set("outdoors", "sanbuguan");
      set("exits", ([
          "west"      : __DIR__"xiaolu2",
          "northeast" : __DIR__"wdroad",
      ]));
      set("no_clean_up", 0);
	set("coor/x", -5000);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
      replace_program(ROOM);
}