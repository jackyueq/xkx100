//Room: sanlaofeng.c ���Ϸ�
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","���Ϸ�");
      set("long",@LONG
ֻ���������ͻأ�������ޱȣ����˶಻�ҷŵ��ڴ����ͷ羰��
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"wuyaling",
          "southup"  : __DIR__"wulaofeng",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
	set("coor/x", -2030);
	set("coor/y", -960);
	set("coor/z", 120);
	setup();
      replace_program(ROOM);
}