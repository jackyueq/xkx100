//Room: santiangate.c ������
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","������");
      set("long",@LONG
�����ǵ�ɽʯ�׵ľ�ͷ�������š����������߾����䵱�����ˡ�
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"ertiangate",
          "southup"  : __DIR__"jinding",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
	set("coor/x", -2030);
	set("coor/y", -1030);
	set("coor/z", 170);
	setup();
      replace_program(ROOM);
}