//Room: qfachanfang.c ����
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","ǧ��������");
      set("long",@LONG
������һ�䰲����������������ǧ�����е��Ӵ�������֮������������
�������������š���λ����ʦ̫���׼�Ů�����������붨��
LONG);
      set("exits",([ /* sizeof() == 1 */
          "west"     : __DIR__"qfadadian",
      ]));
      set("sleep_room", 1);
      set("no_clean_up", 0);
      set("no_fight", 1);
	set("coor/x", -6120);
	set("coor/y", -1070);
	set("coor/z", 80);
	setup();
      replace_program(ROOM);
}