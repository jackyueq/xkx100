//Room: guanyintang.c ������
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","������");
      set("long",@LONG
�����ø߾��¸ڣ�����Σ�£������ľ���������ľ��������Ŀ���ġ���˵
��ɽ�ڴˣ����ѳ�������ɽ�ڴˣ��������裬�ֹ��������֡���ɽ�����ڴ˷�
��ϴ�ģ���ɽ���ɻ���Ϊ�ģ�����ƽ�������ﶫ�¿ɴ�����£�������Լ����
�ɵ����Ƹ�
LONG);
      set("exits",([ /* sizeof() == 1 */
          "eastdown"  : __DIR__"jietuopo",
          "westup"    : __DIR__"guiyunge",
      ]));
      set("outdoors", "emei");
      set("no_clean_up", 0);
	set("coor/x", -6070);
	set("coor/y", -1040);
	set("coor/z", 40);
	setup();
      replace_program(ROOM);
}