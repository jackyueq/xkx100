//Room: shijie2.c ʯ��
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","ʯ��");
      set("long",@LONG
������һ����ʵ��ʯ���ϣ���ʱ���н���ʹ��������߹���һ��
���ͱڣ�һ�������£�̧ͷ��Լ�ɼ������������е������壬������ˮ
���ȣ������Ŀ�������������һ���Ʒ���
LONG);
      set("objects", ([
          __DIR__"npc/guest" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"shibapan",
          "southup"    : __DIR__"zixiaogate",
      ]));
      set("outdoors", "wudang");
//      set("no_clean_up", 0);
	set("coor/x", -2050);
	set("coor/y", -890);
	set("coor/z", 70);
	setup();
      replace_program(ROOM);
}
