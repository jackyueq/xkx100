//Room: hcaeast1.c �����ֶ���
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","�����ֶ���");
      set("long",@LONG
�����Ƕ��һ����ֶ��ȡ���������ͨ��ի�ã�����ͨ���㳡��
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "south" : __DIR__"hcaeast2", 
          "west"  : __DIR__"hcaguangchang", 
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6190);
	set("coor/y", -1170);
	set("coor/z", 190);
	setup();
      replace_program(ROOM);
}