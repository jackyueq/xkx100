// Last Modified by winder on Apr. 25 2001
// �ֹ������ƽ�

inherit F_CLEAN_UP;

int main(object me, string arg)
{
  if (!arg || arg=="1" || arg=="����")
  AUTOSAVE_D->haojie();
  else if (arg=="2" || arg=="�䵱")
  DISASTER_D->disaster(1);
  else if (arg=="3" || arg=="����")
  DISASTER_D->disaster(2);
  else if (arg=="4" || arg=="��ɽ")
  DISASTER_D->disaster(3);
  else if (arg=="5" || arg=="ȫ��")
  DISASTER_D->disaster(4);
  else if (arg=="6" || arg=="��ң")
  DISASTER_D->disaster(5);
  else if (arg=="7" || arg=="����")
  DISASTER_D->disaster(6);
  else if (arg=="8" || arg=="����")
  DISASTER_D->disaster(7);
  else return notify_fail("��ֻ��ѡ��"+   
  "����(1)���䵱(2)������(3)����ɽ(4)��ȫ��(5)����ң(6)������(7)������(8)����һ��\n");
  return 1;
}
int help()
{
write(@help
kaishi [ָ��������]

�����������ṩ��ʦ�ֶ������ƽ١�
Ŀǰ֧�ֵ������У�
����(1)���䵱(2)������(3)����ɽ(4)��ȫ��(5)����ң(6)������(7)������(8)
help
);
  return 1;
}