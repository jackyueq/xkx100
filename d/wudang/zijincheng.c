//Room: zijincheng.c �Ͻ��
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","�Ͻ��");
      set("long",@LONG
�����ػ������Ͻ��ǽ���ܳ������ǽ�ɻ���ʯ��ɽ�����ɣ�
���������ž����پ��ڣ�����Ϊ����·�ڣ�����׳�ۡ�
LONG);
      set("exits",([ /* sizeof() == 1 */
          "north"     : __DIR__"jinding",
          "south"     : __DIR__"jindian",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
	set("coor/x", -2030);
	set("coor/y", -1050);
	set("coor/z", 180);
	setup();
      replace_program(ROOM);
}
