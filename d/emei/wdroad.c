//Room: wdroad.c ���
//Date: Oct.2.1997 by That

inherit ROOM;

void create()
{
      set("short", "�������");
      set("long", @LONG
������һ����������ϣ���ʱ�����˹ҽ�����ҴҶ�����
    ����ͨ���䵱��
LONG);
      set("outdoors", "sanbuguan");
      set("exits", ([
          "southwest" : __DIR__"xiaolu1",
          "northeast" : "/d/wudang/sanbuguan",
      ]));
      set("no_clean_up", 0);
	set("coor/x", -3400);
	set("coor/y", 900);
	set("coor/z", 0);
	setup();
      replace_program(ROOM);
}