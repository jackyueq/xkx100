//Room: shiliang.c ʯ��
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","ʯ��");
      set("long",@LONG
������ɽ���У���һ��ʯ����Ϫ�����������ǾŶɽ�������������
֮ˮ���ڴ˽��㣬��ɫ���ѡ������������С�Ե꣬�������ˣ����С
סЪЪ�����������Ͼ��Ƕ��͵�ʮ�����ˡ�
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northup"    : __DIR__"taizipo",
          "southup"    : __DIR__"shibapan",
          "east"       : __DIR__"shop",
      ]));
      set("objects", ([
          "/clone/medicine/vegetable/shengdi" : random(2),
      ]));
      set("outdoors", "wudang");
	set("coor/x", -2050);
	set("coor/y", -870);
	set("coor/z", 50);
	setup();
      replace_program(ROOM);
}
