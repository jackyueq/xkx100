//Room: qsjie1.c ��ʯ��
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","��ʯ��");
      set("long",@LONG
�쵽����ɽ�ˡ�����һ��ͨ������ɽ����ʯ�ף�����������Σ�����ʮ��
���¡�ʱ���ܼ���Щ������͡�
LONG);
      set("objects", ([
               __DIR__+"npc/youngwoman": 1,
               __DIR__+"npc/puren": 1,
      ]));
      set("outdoors", "sanbuguan");
      set("exits",([ /* sizeof() == 1 */
          "west"       : "/d/chengdu/road1",
          "north"      : __DIR__"xiaolu2",
          "southwest"  : __DIR__"qsjie2",
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6000);
	set("coor/y", -1010);
	set("coor/z", 0);
	setup();
      replace_program(ROOM);
}
