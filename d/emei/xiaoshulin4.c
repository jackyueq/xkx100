//Room: xiaoshulin4.c С����
//Date: Oct. 2 1997 by That

inherit ROOM;
string look_chuang();
string look_paizi();

void create()
{
      set("short","С����");
      set("long",@LONG
���Ƕ���ɽ�𶥻��������һƬС���֡������Ƕ�����Ů�����ǵ��޹���
���������º������һ���ˡ�
LONG);
      set("objects", ([
           __DIR__"npc/xiaosong" : 1,
      ]));
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "northwest" : __DIR__"xiaoshulin3", 
          "north"     : __DIR__"qinggong", 
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6200);
	set("coor/y", -1210);
	set("coor/z", 180);
	setup();
}
int valid_leave(object me, string dir)
{
      mapping myfam;
      myfam = (mapping)me->query("family");
      if ((!myfam || (myfam["family_name"] != "������")) && (dir == "north"))
          return notify_fail("��ô�ĵ��ӣ��봳����Ů���ӵ��޹���\n");
      else  return 1;
}