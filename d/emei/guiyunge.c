//Room: guiyunge.c ���Ƹ�
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","���Ƹ�");
      set("long",@LONG
���Ƹ�ԭ���ƴ����������ʦ�ĵ������δ�������䣬ɮ��ʿ��������
�ؽ������Ƹ�������Ů�壬���Ͽɵִ���������ǹ����á�
LONG);
      set("objects", ([
           __DIR__"npc/boydizi" : 1,
           __DIR__"npc/girldizi" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "eastdown"  : __DIR__"guanyintang",
          "westup"    : __DIR__"chunyangdian",
          "southup"   : __DIR__"yunufeng",
      ]));
      set("outdoors", "emei");
//      set("no_clean_up", 0);
	set("coor/x", -6080);
	set("coor/y", -1040);
	set("coor/z", 50);
	setup();
      replace_program(ROOM);
}