//Room: shanlu2.c ɽ·
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
          "west"     : __DIR__"guangchang",
          "east"     : __DIR__"shanlu3",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
	set("coor/x", -2040);
	set("coor/y", -910);
	set("coor/z", 90);
	setup();
      replace_program(ROOM);
}
