//Room: songlin2.c ���� 
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","ɽ��");
      set("long",@LONG
�����ŵ�����������ȣ����¸��������ˡ�����������
�������ƺ����ڶ��ߣ��㲻���ӿ��˽Ų���
LONG);
      set("outdoors", "jianzhong");
      set("exits",([ /* sizeof() == 1 */
          "west"  : __DIR__"shulin13",
	  "east"   : __DIR__"shulin13",
	  "north"   : __DIR__"dongkou",
          "south"  : __DIR__"shulin4", 
      ]));
	set("coor/x", -400);
	set("coor/y", -450);
	set("coor/z", 0);
	setup();
      replace_program(ROOM);
}