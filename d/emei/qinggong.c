//Room: qinggong.c �����޹�
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","�����޹�");
      set("long",@LONG
���Ƕ���ɽ�𶥻��������һƬС���ֶ����޹���
LONG);
      set("objects", ([
           CLASS_D("emei") + "/zhou" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "south" : __DIR__"xiaoshulin4", 
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6200);
	set("coor/y", -1200);
	set("coor/z", 180);
	setup();
      replace_program(ROOM);
}