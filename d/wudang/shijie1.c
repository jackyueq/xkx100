//Room: shijie1.c ʯ��
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","ʯ��");
      set("long",@LONG
������һ����ʵ��ʯ���ϣ���ʱ���н���ʹ��������߹���һ��
���ͱڣ�һ�������£�̧ͷ��Լ�ɼ������������е������壬������ˮ
���ȣ������Ŀ�������
LONG);
      set("objects", ([
          __DIR__+"npc/guest": 2,
      ]));
      set("outdoors", "wudang");
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"xuanyuegate",
          "southup"    : __DIR__"yuzhengong",
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -2050);
	set("coor/y", -810);
	set("coor/z", 30);
	setup();
      replace_program(ROOM);
}
