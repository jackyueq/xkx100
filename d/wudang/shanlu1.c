//Room: shanlu1.c ɽ·
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","ɽ·");
      set("long",@LONG
�����ڵ�ɽ��·���ϣ�·�����Ҹ���һ����������������������ɽ
��ɽ��������ȥ����������ľ�е�����������Ļ�С�
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northup"  : __DIR__"haohanpo",
          "southup"  : __DIR__"taizipo",
          "east"     : __DIR__"mozhenjing",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
	set("coor/x", -2050);
	set("coor/y", -850);
	set("coor/z", 50);
	setup();
      replace_program(ROOM);
}
