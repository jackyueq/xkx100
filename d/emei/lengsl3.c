//Room: lengsl3.c ��ɼ��
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","��ɼ��");
      set("long",@LONG
����һƬ������յ���ɼ�֡�����Ҳ�ϱ�����������ɼ������һ�飬�ÿ�
֦��Ҷï����һ�����ɡ��������գ��������ڵ�˿��Ҳ�ޡ������Ϻ��Ŀ�
֦��Ҷ����Ȼ�οͺ���̤��˴���
LONG);
      set("exits",([ /* sizeof() == 1 */
          "west"      : __DIR__"bashisipan2",
          "northeast" : __DIR__"lengsl2",
          "southup"   : __DIR__"lengsl4",
      ]));
      set("objects",([ 
          __DIR__"npc/jumang" : 1,
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6220);
	set("coor/y", -1110);
	set("coor/z", 160);
	setup();
      replace_program(ROOM);
}