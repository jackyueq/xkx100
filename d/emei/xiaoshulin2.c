//Room: xiaoshulin2.c С����
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","С����");
      set("long",@LONG
���Ƕ���ɽ�𶥻��������һƬС���֡�����û��·����������ϡ��Щ��
�����ƺ��������߹���
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "south"   : __DIR__"xiaoshulin3", 
          "north"   : __DIR__"xiaoshulin1", 
      ]));
      set("objects",([
                "/clone/medicine/vegetable/badou" : random(2),
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6210);
	set("coor/y", -1190);
	set("coor/z", 180);
	setup();
      replace_program(ROOM);
}