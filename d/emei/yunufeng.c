//Room: yunufeng.c ��Ů��
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","��Ů��");
      set("long",@LONG
���ǹ��Ƹ�ߵ���Ů�壬�嶥��һ���ĳ߼�����С�أ������ĳߣ��ļ���
�ݣ���Ϊ��Ů��ԡ֮������ʱ�ݴ�ʷ��鮣����ڴ˽�é���ӣ������ж�������
��������ʳ�˼��̻�������Ů�·���Ϊ������ʳ�
LONG);
      set("objects", ([
           CLASS_D("emei") + "/fang" : 1,
           "/clone/medicine/vegetable/fangfeng" : random(2),
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"guiyunge",
      ]));
      set("outdoors", "emei");
	set("coor/x", -6080);
	set("coor/y", -1050);
	set("coor/z", 60);
	setup();
      replace_program(ROOM);
}