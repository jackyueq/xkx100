//Room: songlin2.c ���� 
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","ɽ��");
      set("long",@LONG
˳��СϪ���㲻֪������������һ���ľ���ɽ�ȣ�
��������ɽ�����á�ֻ�Ǳ�����������������
׳��Ǻ�ĵ��������������ܵļž���
LONG);
      set("outdoors", "jianzhong");
      set("exits",([ /* sizeof() == 1 */
          "west"  : __DIR__"shulin14",
	  "east"   : __DIR__"shulin14",
	  "north"   : __DIR__"shangu",
          "south"  : __DIR__"shulin3", 
      ]));
	set("coor/x", -400);
	set("coor/y", -470);
	set("coor/z", 0);
	setup();
      replace_program(ROOM);
}