//Room: wulaofeng.c ���Ϸ�
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","���Ϸ�");
      set("long",@LONG
ֻ���������ͻأ�������ޱȣ����˶಻�ҷŵ��ڴ����ͷ羰��
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"sanlaofeng",
          "southup"  : __DIR__"hutouyan",
      ]));
      set("objects",([ /* sizeof() == 1 */
          "/clone/medicine/vegetable/tenghuang" : random(2),
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
	set("coor/x", -2030);
	set("coor/y", -970);
	set("coor/z", 130);
	setup();
      replace_program(ROOM);
}