//Room: gudelin3.c �ŵ���
//Date: Oct. 2 1997 by That

inherit ROOM;
string look_shibei();

void create()
{
      set("short","�ŵ���");
      set("long",@LONG
����һƬ���ܵ��ľ�֣�������ͦ���Σ�֦Ҷ����������������ӵ�𣬾�
˵��������֮�࣬Ҫ�ǲ���Ϥ���κ�������·��������һƬ�յأ���ֻ�ľ׮
�ų�÷��ģ����
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "north"     : __DIR__"caodi",
          "southeast" : __DIR__"gudelin2",
          "southwest" : __DIR__"gudelin2",
          "northeast" : __DIR__"gudelin1",
          "northwest" : __DIR__"gudelin1",
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6130);
	set("coor/y", -1080);
	set("coor/z", 50);
	setup();
      replace_program(ROOM);
}